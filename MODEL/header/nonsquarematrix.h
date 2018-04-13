#ifndef NONSQUAREMATRIX_H
#define NONSQUAREMATRIX_H

#include "matrix.h"

template <class T =double>
class NonSquareMatrix : public Matrix<T> {
public:
    NonSquareMatrix(unsigned int, unsigned int);
    NonSquareMatrix(const NonSquareMatrix<T>&);   //costruttore di copia
    ~NonSquareMatrix();  //distruttore
    NonSquareMatrix<T>* clone() const;
    Matrix<T>* operator*(const Matrix<T>&) const;   //operazioni fra matrici
    NonSquareMatrix<T>* transpose() const;
    unsigned int rank() const;  //rango della matrice

    NonSquareMatrix<T>* operator+(const Matrix<T>&) const;
    NonSquareMatrix<T>* operator-(const Matrix<T>&) const;
    NonSquareMatrix<T>* operator*(const int&) const;
};

#include "../implementation/nonsquarematrix.cpp"

#endif // NONSQUAREMATRIX_H
