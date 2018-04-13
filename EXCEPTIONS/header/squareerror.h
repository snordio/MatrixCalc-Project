#ifndef SQUAREERROR_H
#define SQUAREERROR_H

#include "matrixerror.h"

class SquareError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // SQUAREERROR_H
