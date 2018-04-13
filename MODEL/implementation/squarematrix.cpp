#include "../../MODEL/header/matrix.h"
#include "../../MODEL/header/squarematrix.h"
#include "../../MODEL/header/nonsquarematrix.h"
#include <cstdlib>

//Costruttore standard
template<class T>
SquareMatrix<T>::SquareMatrix(unsigned int n) : Matrix<T>::Matrix(n) {
}

//Costruttore di copia
template<class T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& mat) : Matrix<T>::Matrix(mat) {}

//Distruttore
template<class T>
SquareMatrix<T>::~SquareMatrix() {}

//Matrice identità
template <class T>
SquareMatrix<T> SquareMatrix<T>::identity(unsigned int n) {
    SquareMatrix<T> id(n);
    for(unsigned int i=0; i<n; ++i)
        id(i,i)=T(1);
    return id;
}

template<class T>
SquareMatrix<T>* SquareMatrix<T>::clone() const {return new SquareMatrix<T>(*this);}

//Traccia della matrice quadrata
template<class T>
T SquareMatrix<T>::trace() const {
    T trace=T(0);
    unsigned int n=this->getRows();
    for (unsigned int i=0; i<n*n; i+=n+1)
        trace+=this->values[i];
    return trace;
}

//Determinante della matrice quadrata
template <class T>
T SquareMatrix<T>::determinant() const {
    unsigned int n=this->getRows();
    SquareMatrix<T> tmp(*this);
    int k=tmp.gauss();
        if(abs(k)!=n)
            return T(0);
        T aux = T(1);
        for(unsigned int i=0; i<n*n; i+=n+1)
            aux *= tmp.values[i];
        if(k>0) return aux;
        return aux*(-1);
}

//Rango della matrice quadrata
template <class T>
unsigned int SquareMatrix<T>::rank() const {
    SquareMatrix<T> tmp(*this);
    return abs(tmp.gauss());
}

//Inversa della matrice quadrata
template <class T>
SquareMatrix<T>* SquareMatrix<T>::inverted() const {
    SquareMatrix<T>* ext = new SquareMatrix<T>(SquareMatrix<T>::identity(this->getRows()));
    SquareMatrix<T> tmp(*this);
    tmp.inverseExt(ext);
    return ext;
}

//Inversext
template<class T>
void SquareMatrix<T>::inverseExt(SquareMatrix<T>* mat) {
    unsigned int n=this->getRows();
    if(abs(this->gauss(mat))!=n) throw InverseError();
    for(int i=n-1; i!=-1; --i){
        T coeff = T(1)/(*this)(i,i);
        for(unsigned int j=0; j<n; ++j)
            (*this)(i,j)*=coeff;
        for(unsigned int j=0; j<n; ++j)
            (*mat)(i,j)*=coeff;
        for(unsigned int j=i+1; j<n; j++){
            if((*this)(i,j) == T(0))
                continue;
            for(unsigned int k=0; k<n; k++)
                (*mat)(i,k)-=(*mat)(j,k)*(*this)(i,j);
            (*this)(i,j) = T(0);
        }
    }
}

//Addizione fra 2 matrici
template<class T>
SquareMatrix<T>* SquareMatrix<T>::operator+(const Matrix<T>& mat) const {
    if(this->rows!=mat.getRows() || this->columns!=mat.getColumns()) throw AdditionError();
    unsigned int n=this->getRows();
    SquareMatrix<T>* sum = new SquareMatrix<T>(n);
    for (unsigned int i=0; i<n; ++i) {
        for (unsigned int j=0; j<n; ++j) {
            (*sum)(i,j)=(*this)(i,j)+mat(i,j);
        }
    }
    return sum;
}

//Sottrazione fra 2 matrici
template<class T>
SquareMatrix<T>* SquareMatrix<T>::operator-(const Matrix<T>& mat) const {
    if(this->rows!=mat.getRows() || this->columns!=mat.getColumns()) throw SubtractionError();
    unsigned int n=this->getRows();
    SquareMatrix<T>* diff = new SquareMatrix<T>(n);
    for (unsigned int i=0; i<n; ++i) {
        for (unsigned int j=0; j<n; ++j) {
            (*diff)(i,j)=(*this)(i,j)-mat(i,j);
        }
    }
    return diff;
}

//Moltiplicazione fra 2 matrici
template<class T>
Matrix<T>* SquareMatrix<T>::operator*(const Matrix<T>& mat) const {
    if(this->columns!=mat.getRows()) throw MultiplicationError();
    unsigned int r=this->getRows();
    unsigned int c1=this->getColumns();
    unsigned int c2=mat.getColumns();
    Matrix<T>* prod;
    if(r==c2)
        prod = new SquareMatrix<T>(r);  //Quadrata per quadrata && r>>0 -> algoritmo strassen più efficiente
    prod = new NonSquareMatrix<T>(r, c1);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<c2; ++j) {
            for (unsigned int k=0; k<c1; ++k) {
                (*prod)(i,j)+=(*this)(i,k)*mat(k,j);
            }
        }
    }
    return prod;
}

//Matrice trasposta
template<class T>
SquareMatrix<T>* SquareMatrix<T>::transpose() const{
    unsigned int n=this->getRows();
    SquareMatrix<T>* trans = new SquareMatrix<T>(n);
    for (unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<n; j++) {
            (*trans)(j,i)=(*this)(i,j);
        }
    }
    return trans;
}

//Moltiplicazione fra matrice e scalare
template<class T>
SquareMatrix<T>* SquareMatrix<T>::operator*(const int& scalar) const {
    unsigned int n=this->getRows();
    SquareMatrix<T>* prod = new SquareMatrix<T>(n);
    for (unsigned int i=0; i<n; ++i) {
        for (unsigned int j=0; j<n; ++j) {
            (*prod)(i,j)=(*this)(i,j)*T(scalar);
        }
    }
    return prod;
}
