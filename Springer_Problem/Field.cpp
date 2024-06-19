//
// Created by Carlo Wolter on 30.01.23.
//

#include "Piece.h"
#include "Field.h"

void Field::init(unsigned short row, char column, Piece *pPiece)
{
    this -> row = row;
    this -> column = column;
    this -> pPiece = pPiece;
}

void Field::setPiece(Piece *pPiece)
{
    this-> pPiece = pPiece;
}

void Field::setIfPawn(bool ifPawn)
{
    this-> ifPawn = ifPawn;
}

Piece *Field::getPiece()
{
    return pPiece;
}

bool Field::getIfPawn()
{
    return ifPawn;
}

std::stringstream Field::draw() {

    stringstream Field;

    if (pPiece != NULL)
    {
        Field << pPiece->draw().str();
    }else Field << "";

    return Field;
}