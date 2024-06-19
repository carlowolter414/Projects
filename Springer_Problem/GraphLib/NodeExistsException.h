//
// Created by rroters-lap on 1/7/23.
//

#ifndef FAP_LAB3_NODEEXISTSEXCEPTION_H
#define FAP_LAB3_NODEEXISTSEXCEPTION_H

#include <iostream>
#include <exception>

class NodeExistsException : public std::exception {
public:
    // Constructor
    NodeExistsException();

    // Destructor
    ~NodeExistsException();

    // Returns a C-style character string describing the general cause of the current error
    const char* what();

};


#endif //FAP_LAB3_NODEEXISTSEXCEPTION_H
