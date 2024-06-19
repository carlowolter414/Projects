#include <iostream>
#include "GraphLib.h"

#include "Chessboard.h"
#include "Field.h"

Chessboard *Init();
Chessboard *InitBoard1();
Graph *EdgeInit(Chessboard *chessboard);
void testingChessboardFind();
void testingChessboardDraw();

int main()
{
    Chessboard *chessboard = Init();

    cout << chessboard->draw().str() << endl;

    Graph graph = chessboard->initializeGraph();

    chessboard->findShortestPath(graph);
}

void testingChessboardDraw()
{
    stringstream board = InitBoard1()->draw();
    cout << board.str() << endl;
}

Chessboard *Init()
{
    Chessboard *chessboard = new Chessboard();
    // user input for file name
    string fileName;
    cout << "Bitte geben Sie einen File Namen ein: ";
    cin >> fileName;
    ifstream file;

    file.open("/Users/carlo/Projects/fap/SemesterProjektWS2223/TestData/" + fileName);
    // if file can not open
    if (!file.is_open())
    {
        cerr << "Error opening file " << fileName << "." << endl;
        exit(1);
    }

    chessboard->initialize(file);
    file.close();

    return chessboard;
}

Chessboard *InitBoard1()
{
    Chessboard *chessboard = new Chessboard();
    // user input for file name

#if 1
    string fileName = "Board1.txt";
    ifstream file;

    file.open("/Users/carlo/Projects/fap/SemesterProjektWS2223/TestData/" + fileName);
    // if file can not open
    if (!file.is_open())
    {
        cerr << "Error opening file " << fileName << "." << endl;
        exit(1);
    }


    chessboard->initialize(file);
    file.close();
#endif
    return chessboard;
}

void testingChessboardFind()
{
    Chessboard *chessboard = InitBoard1();
    cout << chessboard->draw().str() << endl;

    cout << "Knight at row: " << chessboard->findKnight().getRow()
    << " and at column: " << chessboard->findKnight().getColumn() << endl;

    cout << "King at row: " << chessboard->findKing().getRow()
         << " and at column: " << chessboard->findKing().getColumn() << endl;
}