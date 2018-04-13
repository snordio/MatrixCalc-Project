#ifndef MATRIXERROR_H
#define MATRIXERROR_H

#include<stdexcept>

class MatrixError : public std::exception {
public:
    const char* what() const throw();
};

#endif // MATRIXERROR_H
