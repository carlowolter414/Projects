//
// Created by Carlo Wolter on 01.02.23.
//

#ifndef SEMESTERPROJEKTWS2223_PAWN_H
#define SEMESTERPROJEKTWS2223_PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
private:
    Color color;
public:
    Pawn(Color color) : color(color) {}

    stringstream draw()
    {
        stringstream Pawn;
        if (color == Color::WHITE) {
            Pawn << "b";
        } else if (color == Color::BLACK)
        {
            Pawn << "B";
        }
        return Pawn;
    }
};

#endif //SEMESTERPROJEKTWS2223_PAWN_H
