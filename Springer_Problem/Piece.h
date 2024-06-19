//
// Created by Carlo Wolter on 30.01.23.
//

#ifndef SEMESTERPROJEKTWS2223_PIECE_H
#define SEMESTERPROJEKTWS2223_PIECE_H

#include "Color.h"
#include <iostream>

using namespace std;

class Piece
{
public:
    virtual std::stringstream draw() = 0;
};

#endif //SEMESTERPROJEKTWS2223_PIECE_H
