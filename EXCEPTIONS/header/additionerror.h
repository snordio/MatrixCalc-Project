#ifndef ADDITIONERROR_H
#define ADDITIONERROR_H

#include "matrixerror.h"

class AdditionError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // ADDITIONERROR_H
