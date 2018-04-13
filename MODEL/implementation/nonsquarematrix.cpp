#include "../../MODEL/header/matrix.h"
#include "../../MODEL/header/nonsquarematrix.h"
#include "../../MODEL/header/squarematrix.h"

//Costruttore standard
template<class T>
NonSquareMatrix<T>::NonSquareMatrix(unsigned int r, unsigned int c) : Matrix<T>::Matrix(r,c) {}

//Costruttore di copia
template<class T>
NonSquareMatrix<T>::NonSquareMatrix(const NonSquareMatrix<T>& mat) : Matrix<T>::Matrix(mat) {}

//Distruttore
template<class T>
NonSquareMatrix<T>::~NonSquareMatrix() {}

template<class T>
NonSquareMatrix<T>* NonSquareMatrix<T>::clone() const {return new NonSquareMatrix<T>(*this);}

//Moltiplicazione fra 2 matrici
template<class T>
Matrix<T>* NonSquareMatrix<T>::operator*(const Matrix<T>& mat) const {
    if(this->columns!=mat.getRows()) throw MultiplicationError();
    unsigned int r=this->getRows();
    unsigned int c=mat.getColumns();
    unsigned int c1=this->getColumns();
    Matrix<T>* prod;
    if(r==c){
        prod = new SquareMatrix<T>(r);
    }
    else prod = new NonSquareMatrix<T>(r, c);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c; ++j) {
            for (unsigned int k=0; k<c1; ++k) {
                (*prod)(i,j)+=(*this)(i,k)*mat(k,j);
            }
        }
    }
    return prod;
}

//Matrice trasposta
template<class T>
NonSquareMatrix<T>* NonSquareMatrix<T>::transpose() const{
    unsigned int r=this->getRows();
    unsigned int c=this->getColumns();
    NonSquareMatrix<T>* trans = new NonSquareMatrix<T>(c, r);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c; ++j) {
            (*trans)(j,i)=(*this)(i,j);
        }
    }
    return trans;
}

//Rango della matrice quadrata
template <class T>
unsigned int NonSquareMatrix<T>::rank() const {
    NonSquareMatrix<T> tmp(*this);
    return abs(tmp.gauss());
}

//Addizione fra 2 matrici
template<class T>
NonSquareMatrix<T>* NonSquareMatrix<T>::operator+(const Matrix<T>& mat) const {
    if(this->rows!=mat.getRows() || this->columns!=mat.getColumns()) throw AdditionError();
    unsigned int r=this->getRows();
    unsigned int c=this->getColumns();
    NonSquareMatrix<T>* sum = new NonSquareMatrix<T>(r,c);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c; ++j) {
            (*sum)(i,j)=(*this)(i,j)+mat(i,j);
        }
    }
    return sum;
}

//Sottrazione fra 2 matrici
template<class T>
NonSquareMatrix<T>* NonSquareMatrix<T>::operator-(const Matrix<T>& mat) const {
    if(this->rows!=mat.getRows() || this->columns!=mat.getColumns()) throw SubtractionError();
    unsigned int r=this->getRows();
    unsigned int c=this->getColumns();
    NonSquareMatrix<T>* diff = new NonSquareMatrix<T>(r,c);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c; ++j) {
            (*diff)(i,j)=(*this)(i,j)-mat(i,j);
        }
    }
    return diff;
}

//Moltiplicazione fra matrice e scalare
template<class T>
NonSquareMatrix<T>* NonSquareMatrix<T>::operator*(const int& scalar) const {
    unsigned int r=this->getRows();
    unsigned int c=this->getColumns();
    NonSquareMatrix<T>* prod = new NonSquareMatrix<T>(r, c);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c; ++j) {
            (*prod)(i,j)=(*this)(i,j)*T(scalar);
        }
    }
    return prod;
}
