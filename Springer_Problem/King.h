//
// Created by Carlo Wolter on 01.02.23.
//

#ifndef SEMESTERPROJEKTWS2223_KING_H
#define SEMESTERPROJEKTWS2223_KING_H

#include "Piece.h"
#include <iostream>
#include <fstream>
#include <sstream>


class King : public Piece
{
private:
    Color color;
public:
    King(Color color) : color(color) {}

    stringstream draw()
    {
        stringstream King;
        if (color == Color::WHITE) {
            King << "k";
        } else if (color == Color::BLACK)
        {
            King << "K";
        }
        return King;
    }
};


#endif //SEMESTERPROJEKTWS2223_KING_H
