//
// Created by rroters-lap on 1/7/23.
//

#include "NodeExistsException.h"

// Constructor
NodeExistsException::NodeExistsException() {

}

// Destructor
NodeExistsException::~NodeExistsException() noexcept {

}

// Message to return

const char* NodeExistsException::what(){
    return "There already exists a node with the same id";
}