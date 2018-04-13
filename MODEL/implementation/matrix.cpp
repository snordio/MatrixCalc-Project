#include "../../MODEL/header/matrix.h"
#include "../../EXCEPTIONS/header/assignationerror.h"
#include "../../EXCEPTIONS/header/outofrangeerror.h"
#include "../../EXCEPTIONS/header/inverseerror.h"
#include "../../EXCEPTIONS/header/multiplicationerror.h"
#include "../../EXCEPTIONS/header/subtractionerror.h"
#include "../../EXCEPTIONS/header/additionerror.h"
#include "../../EXCEPTIONS/header/squareerror.h"
#include<stdexcept>
#include<typeinfo>

//Costruttore a 1 parametro
template<class T>
Matrix<T>::Matrix(unsigned int n) : rows(n), columns(n), values(n*n) {}

//Costruttore a 2 parametri
template<class T>
Matrix<T>::Matrix(unsigned int r, unsigned int c) : rows(r), columns(c), values(r*c) {}

//Costruttore di copia
template<class T>
Matrix<T>::Matrix(const Matrix<T>& mat) : rows(mat.rows), columns(mat.columns), values(mat.values) {}

//Distruttore
template<class T>
Matrix<T>::~Matrix() {}

//Estrai numero righe della matrice
template<class T>
unsigned int Matrix<T>::getRows() const {
    return rows;
}

//Estrai numero colonne della matrice
template<class T>
unsigned int Matrix<T>::getColumns() const {
    return columns;
}

//Operatore assegnazione
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat) {
    if(typeid(*this)!=typeid(mat) || rows!=mat.getRows() || columns!=mat.getColumns()) throw AssignationError();
    if(this != &mat){
        rows=mat.getRows();
        columns=mat.getColumns();
        values.resize(rows*columns);
        for(unsigned int i=0; i<rows; ++i)
            for(unsigned int j=0; j<columns; ++j)
                    values[i*columns+j]=mat(i,j);
    }
    return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const T& t) {
    if(rows!=1 || columns!=1 || values[0]!=T(t)){
        rows=1;
        columns=1;
        values.resize(1);
        values[0] = T(t);
    }
    return *this;
}

//Metodo Gauss
template<class T>
int Matrix<T>::gauss(Matrix<T>* mat){
    int row=0;
    unsigned int r=this->getRows();
    unsigned int c=this->getColumns();
    bool pari=true;
    for(unsigned int col=0; col<c; ++col){
        for(unsigned int i=row; i<r; ++i){
            if((*this)(i,col) != T(0)){
                if(i!=row){
                    if(pari) pari=false;
                    else pari=true;
                    for(unsigned int j=0; j<c; ++j){
                        std::swap((*this)(i,j), (*this)(row,j));
                        (*this)(i,j) = (*this)(i,j) * T(-1);
                    }
                    if(mat){
                        for(unsigned int j=0; j<mat->getColumns(); ++j){
                            std::swap((*mat)(i,j), (*mat)(row,j));
                            (*mat)(i,j) = (*mat)(i,j) * T(-1);
                        }
                    }
                }
                break;
            }
        }
        if((*this)(row,col) == T(0))
            continue;
        for(unsigned int i=row+1; i<r; ++i){
            T coeff=(*this)(i,col)/(*this)(row,col);
            for(unsigned int j=0; j<c; ++j)
                (*this)(i,j)-=(*this)(row,j)*coeff;
            if(mat){
                for(unsigned int j=0; j<mat->getColumns(); ++j)
                    (*mat)(i,j)-=(*mat)(row,j)*coeff;
            }
        }
        if(++row == r){
            if(pari) return row;
            else return -row;
        }
    }
    if(pari) return row;
    else return -row;
}

//Accesso agli elementi della matrice
template<class T>
T& Matrix<T>::operator()(const unsigned int& r, const unsigned int& c) {
    if(r>=rows || c>=columns) throw OutOfRangeError();
    return values[r*columns+c];
}

template<class T>
const T& Matrix<T>::operator()(const unsigned int& r, const unsigned int& c) const {
    if(r>=rows || c>=columns) throw OutOfRangeError();
    return values[r*columns+c];
}

//Operatore uguaglianza
template<class T>
bool Matrix<T>::operator==(const Matrix<T>& mat) const {
    if(typeid(*this)!=typeid(mat) || rows!=mat.getRows() || columns!=mat.getColumns())
        return false;
    for (unsigned int i=0; i<mat.rows; ++i){
        for (unsigned int j=0; j<mat.columns; ++j)
            if((*this)(i,j) != mat(i,j))
                return false;
    }
    return true;
}

//Stampa elementi matrice
template<class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
    for (unsigned int i=0; i<mat.rows; ++i){
        for (unsigned int j=0; j<mat.columns; ++j){
            if(mat(i,j)==0) os << unsigned(mat(i,j)) << "\t";
            else os << mat(i,j) << "\t";
        }
        os << std::endl;
    }
    return os;
}

//Input elementi matrice
template<class T>
std::istream& operator>>(std::istream& is, Matrix<T>& mat) {
    for (unsigned int i=0; i<mat.rows; ++i)
        for (unsigned int j=0; j<mat.columns; ++j)
            is >> mat(i,j);
    return is;
}
