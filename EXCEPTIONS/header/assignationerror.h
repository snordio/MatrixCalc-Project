#ifndef ASSIGNATIONERROR_H
#define ASSIGNATIONERROR_H

#include "matrixerror.h"

class AssignationError : public MatrixError {
public:
    const char* what() const throw();
};

#endif // ASSIGNATIONERROR_H
