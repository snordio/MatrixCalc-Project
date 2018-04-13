#ifndef MULTIPLICATIONERROR_H
#define MULTIPLICATIONERROR_H

#include "matrixerror.h"

class MultiplicationError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // MULTIPLICATIONERROR_H
