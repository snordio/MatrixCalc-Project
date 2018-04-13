#include <QMessageBox>
#include <QIcon>
#include "../header/controllermatrix.h"

ControllerMatrix::ControllerMatrix(ModelMatrix* mm) : MM(mm) {}

ControllerMatrix::~ControllerMatrix() {
    delete MM;
}


void ControllerMatrix::setMatrix(bool operand, unsigned int r, unsigned int c) {
    MM->setMatrix(operand, r, c);
}

void ControllerMatrix::setResult(unsigned int r, unsigned int c){
    MM->setResult(r,c);
}

void ControllerMatrix::add() {
    try{
        MM->add();
    }
    catch (const AdditionError& ad) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(ad.what());
        msgBox.exec();
    }
}

void ControllerMatrix::sub(){
    try{
        MM->sub();
    }
    catch (const SubtractionError& se) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(se.what());
        msgBox.exec();
    }
}

void ControllerMatrix::mult() {
    try{
        MM->mult();
    }
    catch (const MultiplicationError& me) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(me.what());
        msgBox.exec();
    }
}

void ControllerMatrix::multScalar(bool operand, const int& n) {
    try{
        MM->multScalar(operand,n);
    }
    catch (const MatrixError& me) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(me.what());
        msgBox.exec();
    }
}

void ControllerMatrix::trans(bool operand) {
    try{
        MM->trans(operand);
    }
    catch (const MatrixError& me) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(me.what());
        msgBox.exec();
    }
}

void ControllerMatrix::trace(bool operand) {
    try{
        MM->trace(operand);
    }
    catch (const SquareError& se) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(se.what());
        msgBox.exec();
    }
}

void ControllerMatrix::gauss(bool operand) {
    try{
        MM->gauss(operand);
    }
    catch (const MatrixError& me) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(me.what());
        msgBox.exec();
    }
}

void ControllerMatrix::determinant(bool operand) {
    try{
        MM->determinant(operand);
    }
    catch (const SquareError& se) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(se.what());
        msgBox.exec();
    }
}

void ControllerMatrix::rank(bool operand) {
    try{
        MM->rank(operand);
    }
    catch (const MatrixError& me) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(me.what());
        msgBox.exec();
    }
}

void ControllerMatrix::inverse(bool operand) {
    try{
        MM->inverse(operand);
    }
    catch (const InverseError& ie) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(ie.what());
        msgBox.exec();
    }
    catch (const SquareError& se) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(se.what());
        msgBox.exec();
    }
}

Matrix<Complex<Rational> >* ControllerMatrix::getOp1() {
    return MM->getOp1();
}

Matrix<Complex<Rational> >* ControllerMatrix::getOp2() {
    return MM->getOp2();
}

Matrix<Complex<Rational> >* ControllerMatrix::getResult() {
    return MM->getResult();
}
