#ifndef CONTROLLERMATRIX_H
#define CONTROLLERMATRIX_H

#include "../../MODEL/header/matrix.h"
#include "modelmatrix.h"


class ControllerMatrix {
private:
    ModelMatrix* MM;
public:
    ControllerMatrix(ModelMatrix*);
    ~ControllerMatrix();
    void setMatrix(bool, unsigned int, unsigned int);
    void setResult(unsigned int, unsigned int);
    void add();
    void sub();
    void mult();
    void multScalar(bool, const int&);
    void trans(bool);
    void trace(bool);
    void gauss(bool);
    void determinant(bool);
    void rank(bool);
    void inverse(bool);
    Matrix<Complex<Rational> >* getOp1();
    Matrix<Complex<Rational> >* getOp2();
    Matrix<Complex<Rational> >* getResult();
};

#endif // CONTROLLERMATRIX_H
