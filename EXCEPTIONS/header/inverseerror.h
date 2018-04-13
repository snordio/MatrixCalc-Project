#ifndef INVERSEERROR_H
#define INVERSEERROR_H

#include "matrixerror.h"

class InverseError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // INVERSEERROR_H
