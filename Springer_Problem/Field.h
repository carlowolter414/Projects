//
// Created by Carlo Wolter on 30.01.23.
//

#ifndef SEMESTERPROJEKTWS2223_FIELD_H
#define SEMESTERPROJEKTWS2223_FIELD_H

#include "Piece.h"
#include "Color.h"
#include <iostream>
#include <sstream>
#include <string>
#include "GraphLib.h"

using namespace std;

class Field : public Node
{
private:
    unsigned short row;
    char column;
    bool ifPawn = false;
    Piece *pPiece;

public:
    Field(){};
    Field(unsigned short row, char column, Piece *pPiece) :
    row(row), column(column), pPiece(pPiece) {};

    //destuctor
    ~Field(){};

    //getter
    unsigned short getRow() const {return row + 1;};
    char getColumn() const {return column + 'a';}
    Piece *getPiece();
    bool getIfPawn();

    //setter
    void setPiece(Piece *pPiece);
    void setIfPawn(bool ifPawn);

    void init(unsigned short row, char column, Piece *pPiece);
    stringstream draw();
};


#endif //SEMESTERPROJEKTWS2223_FIELD_H
