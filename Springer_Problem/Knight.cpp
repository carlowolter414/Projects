//
// Created by Carlo Wolter on 01.02.23.
//


#include "Piece.h"

#include "Knight.h"

stringstream Knight::draw()
{
    stringstream Knight;
    if (color == Color::WHITE) {
        Knight << "s";
    } else if (color == Color::BLACK)
    {
        Knight << "S";
    }
    return Knight;
}