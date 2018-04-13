#ifndef OUTOFRANGEERROR_H
#define OUTOFRANGEERROR_H

#include "matrixerror.h"

class OutOfRangeError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // OUTOFRANGEERROR_H
