#ifndef SUBTRACTIONERROR_H
#define SUBTRACTIONERROR_H

#include "matrixerror.h"

class SubtractionError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // SUBTRACTIONERROR_H
