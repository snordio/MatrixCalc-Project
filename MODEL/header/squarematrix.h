#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

template<class T =double>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix(unsigned int);
    SquareMatrix(const SquareMatrix<T>&);   //costruttore di copia
    ~SquareMatrix();  //distruttore

    static SquareMatrix<T> identity(unsigned int);  //matrice identità
    T trace() const;    //traccia della matrice
    T determinant() const;  //determinante della matrice
    unsigned int rank() const;  //rango della matrice
    void inverseExt(SquareMatrix<T>*);
    SquareMatrix<T>* inverted() const;  //matrice inversa
    SquareMatrix<T>* clone() const;
    SquareMatrix<T>* operator+(const Matrix<T>&) const; //operazioni fra matrici
    SquareMatrix<T>* operator-(const Matrix<T>&) const;
    Matrix<T>* operator*(const Matrix<T>&) const;
    SquareMatrix<T>* transpose() const;

    SquareMatrix<T>* operator*(const int&) const;
};

#include "../implementation/squarematrix.cpp"

#endif // SQUAREMATRIX_H
