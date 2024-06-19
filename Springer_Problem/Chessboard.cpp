//
// Created by Carlo Wolter on 30.01.23.
//

#include "Chessboard.h"
#include <exception>

void Chessboard::initialize(ifstream &file)
{
    // resize vektor fields and creates 64 fields in it
    fields.resize(8);
    for (int i = 0; i < 8; i++)
    {
        fields[i].resize(8);
        for (int j = 0; j < 8; j++)
        {
            Field &field = fields[i][j];
            field.init(i, j, NULL);
        }
    }
    //
    string line, token;
    char pieceInfo;
    unsigned short row, column;
    // reads file and stores the line in line
    // creates a new string stream
    while (getline(file, line)) {
        stringstream lineStream(line);
        // reads lineStream and stores token until ','
        Color color;
        while (getline(lineStream, token, ',')) {
            pieceInfo = token[0];
            column = token[1] - 'a';
            row = token[2] - '1'; // zeichen '1' bekommt den Wert 0

            // set color
            if (isupper(pieceInfo)) {
                color = Color::BLACK;
            } else color = Color::WHITE;
            // set figure type
            Piece *piece;
            Field &field = fields[row][column];
            switch (tolower(pieceInfo)) {
                case 's':
                    piece = new Knight(color);
                    break;
                case 'k':
                    piece = new King(color);
                    break;
                case 'b':
                    piece = new Pawn(color);
                    field.setIfPawn(true);
                    break;
            }
            field.setPiece(piece);
        }
    }
}

Field Chessboard::findKing()
{
    for (int row = 0; row < fields.size(); row++)
    {
        for (int column = 0; column < fields[row].size(); column++)
        {
            Field field = fields[row][column];
            Piece *piece = field.getPiece();
            if (piece != NULL && typeid (*piece) == typeid (King))
            {
                return fields[row][column];
            }
        }
    }
    try
    {
        throw runtime_error ("Springer / König wurde nicht gefunden!");
    }
    catch (const exception &e)
    {
        cerr << "Exception ist aufgetreten!\n" << e.what() << endl;
    }
}

Field Chessboard::findKnight()
{
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            Field field = fields[row][column];
            Piece *piece = field.getPiece();
            if (piece != NULL && typeid (*piece) == typeid (Knight))
            {
                return fields[row][column];
            }
        }
    }
    try
    {
        throw runtime_error ("Springer / König wurde nicht gefunden!");
    }
    catch (const exception &e)
    {
        cerr << "Exception ist aufgetreten!\n" << e.what() << endl;
    }
}

stringstream Chessboard::draw()
{
    stringstream chessboard;
    Color color = Color::WHITE;
    char blackField = '#', whiteField = '-', print;

    chessboard << endl << "\t";
    for (char row = 'a'; row < 'i'; row++)
    {
        chessboard << " " << row << "\t";
    }
    chessboard << endl;
    for (int i = 0; i != fields.size(); i++)
    {
        chessboard << i + 1 << "\t";
        for (int j = 0; j != fields[i].size(); j++)
        {
            //print = color ? blackField :whiteField;
            print = (color == Color::BLACK) ? blackField : whiteField;
            chessboard << print;

            chessboard << fields[i][j].draw().str();

            chessboard << print;
            chessboard << "\t";
            color = (color == Color::BLACK) ? Color::WHITE : Color::BLACK;
        }
        color = (color == Color::BLACK) ? Color::WHITE : Color::BLACK;
        chessboard << endl;
    }
    return chessboard;
}

Graph Chessboard::initializeGraph()
{
    Graph graph;
    string checka, checkb;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j< 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                for (int l = 0; l < 8; l++)
                {
                    if ((fabs(i-k) == 1 && fabs(j-l) == 2) || (fabs(i-k) == 2 && fabs(j-l) == 1))
                    {
                        if (!fields[i][j].getIfPawn() && !fields[k][l].getIfPawn())
                        {
                            Field &field_src = fields[i][j];
                            Field &field_dst = fields[k][l];
                            Edge *edge = new Edge(field_src, field_dst);
                            graph.addEdge(edge);
                        }
                    }
                }
            }
        }
    }
    return graph;
}

void Chessboard::findShortestPath(Graph &graph)
{
    try
    {
        bool tryException = true;
        for (auto it = graph.getEdges().begin(); it != graph.getEdges().end(); it++)
            if (findKing().getID() == (*it)->getDstNode().getID())
            {
                tryException = false;
                break;
            }
        if (tryException) throw runtime_error("\nEs kann kein Weg zu König gefunden werden!"
                                              "Bauern stehen im Weg!");

        Field KNIGHT = findKnight();
        Field KING = findKing();

        list<Node*> path = graph.findShortestPathDijkstra(&KNIGHT, &KING);
        cout << "Der kürzeste Phat nach Dijkstra ist von Feld:" << endl;
        for (auto it = path.begin(); it != path.end(); it++)
        {
            Field *pathElement = dynamic_cast<Field*>(*it);
            cout << "(" << pathElement->getRow() << " | " << pathElement->getColumn() << ")" << " nach" << endl;
        }
        cout << "zum Feld " << "(" << findKing().getRow() << " | " << findKing().getColumn() << ")" << endl;

    }
    catch (const exception& e)
    {
        cerr << "Exception aufgetreten!\n" << e.what() << endl;

    }
}