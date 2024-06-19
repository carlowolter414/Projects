//
// Created by Carlo Wolter on 01.02.23.
//

#ifndef SEMESTERPROJEKTWS2223_KNIGHT_H
#define SEMESTERPROJEKTWS2223_KNIGHT_H


#include "Piece.h"
#include <iostream>
#include <fstream>
#include <sstream>


class Knight : public Piece
{
private:
    Color color;
    //Field *field;
public:
    Knight(Color color) : color(color) {}
    stringstream draw();
    //void move(Field &field){};
};


#endif //SEMESTERPROJEKTWS2223_KNIGHT_H
