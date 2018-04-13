#ifndef MODELMATRIX_H
#define MODELMATRIX_H

#include <QString>
#include "../../MODEL/header/matrix.h"
#include "../../MODEL/header/complex.h"
#include "../../MODEL/header/rational.h"

class ModelMatrix {
private:
    Matrix<Complex<Rational> >* op1; //matrice operando
    Matrix<Complex<Rational> >* op2; //matrice operando
    Matrix<Complex<Rational> >* result;  //matrice risultato
public:
    ModelMatrix(Matrix<Complex<Rational> >* = 0, Matrix<Complex<Rational> >* =0,
                Matrix<Complex<Rational> >* =0);
    ~ModelMatrix();
    void setMatrix(bool, unsigned int, unsigned int);
    void setResult(unsigned int , unsigned int );
    void add(); //somma tra matrici
    void sub(); //differenza tra matrici
    void mult();    //moltiplicazione tra matrici
    void multScalar(bool, const int&);
    void trans(bool);   //matrice trasposta
    void trace(bool);    //traccia matrice
    void gauss(bool);    //metodo di gauss
    void determinant(bool);  //determinante matrice
    void rank(bool);  //rango matrice
    void inverse(bool); //matrice inversa
    Matrix<Complex<Rational> >* getOp1();
    Matrix<Complex<Rational> >* getOp2();
    Matrix<Complex<Rational> >* getResult();
};

#endif // MODELMATRIX_H
