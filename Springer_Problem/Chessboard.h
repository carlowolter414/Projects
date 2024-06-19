//
// Created by Carlo Wolter on 30.01.23.
//

#ifndef SEMESTERPROJEKTWS2223_CHESSBOARD_H
#define SEMESTERPROJEKTWS2223_CHESSBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

#include "Field.h"
#include "Piece.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"

using namespace std;

class Chessboard {
private:
    // Coordinates, colum and raw for Flied class
    vector<vector<Field>> fields;
public:
    // standard constructor
    Chessboard(){};
    // init Constructor
    void initialize(ifstream &file);
    Graph initializeGraph();
    // Constructor
    void findShortestPath(Graph &graph);
    Field findKnight();
    Field findKing();

    stringstream draw();
};


#endif //SEMESTERPROJEKTWS2223_CHESSBOARD_H
