#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>

template<class T =double>
class Matrix;

template<class T>
std::ostream& operator<<(std::ostream&, const Matrix<T>&);

template<class T>
std::istream& operator>>(std::istream&, Matrix<T>&);

template<class T>
class Matrix {
protected:
    unsigned int rows;
    unsigned int columns;
    std::vector<T> values;
public:
    friend std::ostream& operator<< <> (std::ostream&, const Matrix<T>&);   //stampa elementi matrice
    friend std::istream& operator>> <> (std::istream&, Matrix<T>&);   //input elementi matrice
    Matrix(unsigned int);   //costruttore a 1 parametro
    Matrix(unsigned int, unsigned int); //costruttore a 2 parametri
    Matrix(const Matrix<T>&);   //costruttore di copia
    virtual ~Matrix();  //distruttore
    virtual Matrix<T>* clone() const =0;
    unsigned int getRows() const;   //estrazione righe e colonne
    unsigned int getColumns() const;

    Matrix<T>& operator=(const Matrix<T>&); //operazioni fra matrici
    virtual Matrix<T>* operator+(const Matrix<T>&) const =0;
    virtual Matrix<T>* operator-(const Matrix<T>&) const =0;
    virtual Matrix<T>* operator*(const Matrix<T>&) const =0;
    virtual Matrix<T>* transpose() const =0;    //matrice trasposta
    virtual unsigned int rank() const =0;  //rango della matrice
    int gauss(Matrix<T>* =0);  //metodo di Gauss

    Matrix<T>& operator=(const T&); //operazioni con scalare
    virtual Matrix<T>* operator*(const int&) const =0;

    T& operator()(const unsigned int&, const unsigned int&);    //accesso agli elementi della matrice
    const T& operator()(const unsigned int&, const unsigned int&) const;

    bool operator==(const Matrix<T>&) const;    //operatore uguaglianza
};

#include "../implementation/matrix.cpp"

#endif // MATRIX_H
