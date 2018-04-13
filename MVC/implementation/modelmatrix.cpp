#include "../../MVC/header/modelmatrix.h"
#include "../../MODEL/header/nonsquarematrix.h"
#include "../../MODEL/header/squarematrix.h"


ModelMatrix::ModelMatrix(Matrix<Complex<Rational> >* mat1, Matrix<Complex<Rational> >* mat2, Matrix<Complex<Rational> >* mat3) : op1(mat1),
    op2(mat2), result(mat3) {}

ModelMatrix::~ModelMatrix() {
    delete op1;
    delete op2;
    delete result;
}

void ModelMatrix::setMatrix(bool operand, unsigned int r, unsigned int c) {
    if(operand){
        delete op1;
        if(r==c) op1 = new SquareMatrix<Complex<Rational> >(r);
        else op1 = new NonSquareMatrix<Complex<Rational> >(r,c);
    }
    else{
        delete op2;
        if(r==c) op2 = new SquareMatrix<Complex<Rational> >(r);
        else op2 = new NonSquareMatrix<Complex<Rational> >(r,c);
    }
}

void ModelMatrix::setResult(unsigned int r, unsigned int c) {
    delete result;
    if(r==c) result = new SquareMatrix<Complex<Rational> >(r);
    else result = new NonSquareMatrix<Complex<Rational> >(r,c);
}

void ModelMatrix::add() {
    result = *op1 + *op2;
}

void ModelMatrix::sub() {
    result = *op1 - *op2;
}

void ModelMatrix::mult() {
    result = *op1 * *op2;
}

void ModelMatrix::multScalar(bool operand, const int& n) {
    if(operand) result = *op1 * n;
    else result = *op2 * n;
}

void ModelMatrix::trans(bool operand) {
    if(operand) result = op1->transpose();
    else result = op2->transpose();
}

void ModelMatrix::trace(bool operand) {
    if(operand){
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op1)) throw SquareError();
        else *result = static_cast<SquareMatrix<Complex<Rational> >*>(op1)->trace();
    }
    else{
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op2)) throw SquareError();
        else *result = static_cast<SquareMatrix<Complex<Rational> >*>(op2)->trace();
    }
}

void ModelMatrix::gauss(bool operand) {
    if(operand){
        op1->gauss();
        delete result;
        result = op1->clone();
    }
    else{
        op2->gauss();
        delete result;
        result = op2->clone();
    }
}

void ModelMatrix::determinant(bool operand) {
    if(operand){
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op1)) throw SquareError();
        else *result = static_cast<SquareMatrix<Complex<Rational> >*>(op1)->determinant();
    }
    else{
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op2)) throw SquareError();
        else *result = static_cast<SquareMatrix<Complex<Rational> >*>(op2)->determinant();
    }
}

void ModelMatrix::rank(bool operand) {
    if(operand) *result = Complex<Rational>(op1->rank());
    else *result = Complex<Rational>(op2->rank());
}

void ModelMatrix::inverse(bool operand) {
    if(operand){
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op1)) throw SquareError();
        else result = static_cast<SquareMatrix<Complex<Rational> >*>(op1)->inverted();
    }
    else{
        if(!dynamic_cast<SquareMatrix<Complex<Rational> >*>(op2)) throw SquareError();
        else result = static_cast<SquareMatrix<Complex<Rational> >*>(op2)->inverted();
    }
}

Matrix<Complex<Rational> >* ModelMatrix::getOp1() {
    return op1;
}

Matrix<Complex<Rational> >* ModelMatrix::getOp2() {
    return op2;
}

Matrix<Complex<Rational> >* ModelMatrix::getResult() {
    return result;
}
