#include "../header/mainwindow.h"
#include "ui_mainwindow.h"
#include "../header/parser.h"
#include "../../EXCEPTIONS/header/inputerror.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CM = new ControllerMatrix(new ModelMatrix());
    configureComponents();
}

MainWindow::~MainWindow() {
    delete CM;
    delete ui;
}

void MainWindow::configureComponents() {
    ui->spinBoxRowsA->setMinimum(0);
    ui->spinBoxRowsB->setMinimum(0);
    ui->spinBoxColumnsA->setMinimum(0);
    ui->spinBoxColumnsB->setMinimum(0);
    ui->tableWidgetA->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetB->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetResult->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MainWindow::closeEvent(QCloseEvent* event) {
    QMessageBox::StandardButton button = QMessageBox::question( this, "Matrix Calculator",
                                                                tr("Sei sicuro di voler uscire?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (button!=QMessageBox::Yes)
        event->ignore();
    else
        event->accept();
}

void MainWindow::setValuesA(unsigned int r, unsigned int c) {
    try {
        for(unsigned int i=0; i<r; ++i)
            for(unsigned int j=0; j<c; ++j)
                (*CM->getOp1())(i,j)=Parser::stringToComplex(ui->tableWidgetA->item(i,j)->text());
    }
    catch (const InputError& ie) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(ie.what());
        msgBox.exec();
    }
}

void MainWindow::setValuesB(unsigned int r, unsigned int c) {
    try {
        for(unsigned int i=0; i<r; ++i)
            for(unsigned int j=0; j<c; ++j)
                (*CM->getOp2())(i,j)=Parser::stringToComplex(ui->tableWidgetB->item(i,j)->text());
    }
    catch (const InputError& ie) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Attenzione");
        msgBox.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgBox.setText(ie.what());
        msgBox.exec();
    }
}

void MainWindow::setOperandA() {
    CM->setMatrix(true,ui->tableWidgetA->rowCount(),ui->tableWidgetA->columnCount());
    setValuesA(ui->tableWidgetA->rowCount(), ui->tableWidgetA->columnCount());
}

void MainWindow::setOperandB() {
    CM->setMatrix(false,ui->tableWidgetB->rowCount(),ui->tableWidgetB->columnCount());
    setValuesB(ui->tableWidgetB->rowCount(), ui->tableWidgetB->columnCount());
}

void MainWindow::printResult() {
    unsigned int r=(*CM->getResult()).getRows();
    unsigned int c=(*CM->getResult()).getColumns();
    ui->tableWidgetResult->setRowCount(r);
    ui->tableWidgetResult->setColumnCount(c);
    for(unsigned int i=0; i<r; ++i)
        for(unsigned int j=0; j<c; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(Parser::ComplexToString((*CM->getResult())(i,j)));
            ui->tableWidgetResult->setItem(i,j,item);
        }
}

void MainWindow::setZero(bool spin) {
    if(spin){
        for(int i=0; i<ui->tableWidgetA->rowCount(); ++i)
                for(int j=0; j<ui->tableWidgetA->columnCount() ; ++j)
                    ui->tableWidgetA->setItem(i, j, new QTableWidgetItem(QString("0")));
    }
    else {
        for(int i=0; i<ui->tableWidgetB->rowCount(); ++i)
                for(int j=0; j<ui->tableWidgetB->columnCount() ; ++j)
                    ui->tableWidgetB->setItem(i, j, new QTableWidgetItem(QString("0")));
    }
}

void MainWindow::on_spinBoxRowsA_valueChanged(int n) {
    ui->tableWidgetA->setRowCount(n);
    setZero(true);
}

void MainWindow::on_spinBoxColumnsA_valueChanged(int n) {
    ui->tableWidgetA->setColumnCount(n);
    setZero(true);
}

void MainWindow::on_spinBoxRowsB_valueChanged(int n) {
    ui->tableWidgetB->setRowCount(n);
    setZero(false);
}

void MainWindow::on_spinBoxColumnsB_valueChanged(int n) {
    ui->tableWidgetB->setColumnCount(n);
    setZero(false);
}

void MainWindow::on_ButtonMult_clicked() {
    setOperandA();
    setOperandB();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp2()).getColumns());
    CM->mult();
    printResult();
}

void MainWindow::on_ButtonAdd_clicked() {
    setOperandA();
    setOperandB();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->add();
    printResult();
}

void MainWindow::on_ButtonSub_clicked() {
    setOperandA();
    setOperandB();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->sub();
    printResult();
}

void MainWindow::on_ButtonMultScalarA_clicked() {
    setOperandA();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->multScalar(true,ui->spinBoxA->value());
    printResult();
}

void MainWindow::on_ButtonMultScalarB_clicked() {
    setOperandB();
    CM->setResult((*CM->getOp2()).getRows(),(*CM->getOp2()).getColumns());
    CM->multScalar(false,ui->spinBoxB->value());
    printResult();
}

void MainWindow::on_ButtonTransA_clicked() {
    setOperandA();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->trans(true);
    printResult();
}

void MainWindow::on_ButtonTransB_clicked() {
    setOperandB();
    CM->setResult((*CM->getOp2()).getRows(),(*CM->getOp2()).getColumns());
    CM->trans(false);
    printResult();
}

void MainWindow::on_ButtonTraceA_clicked() {
    setOperandA();
    CM->setResult(1,1);
    CM->trace(true);
    printResult();
}

void MainWindow::on_ButtonTraceB_clicked() {
    setOperandB();
    CM->setResult(1,1);
    CM->trace(false);
    printResult();
}

void MainWindow::on_ButtonGaussA_clicked() {
    setOperandA();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->gauss(true);
    printResult();
}

void MainWindow::on_ButtonGaussB_clicked() {
    setOperandB();
    CM->setResult((*CM->getOp2()).getRows(),(*CM->getOp2()).getColumns());
    CM->gauss(false);
    printResult();
}

void MainWindow::on_ButtonDeterminantA_clicked() {
    setOperandA();
    CM->setResult(1,1);
    CM->determinant(true);
    printResult();
}

void MainWindow::on_ButtonDeterminantB_clicked() {
    setOperandB();
    CM->setResult(1,1);
    CM->determinant(false);
    printResult();
}

void MainWindow::on_ButtonRankA_clicked() {
    setOperandA();
    CM->setResult(1,1);
    CM->rank(true);
    printResult();
}

void MainWindow::on_ButtonRankB_clicked() {
    setOperandB();
    CM->setResult(1,1);
    CM->rank(false);
    printResult();
}

void MainWindow::on_ButtonInverseA_clicked() {
    setOperandA();
    CM->setResult((*CM->getOp1()).getRows(),(*CM->getOp1()).getColumns());
    CM->inverse(true);
    printResult();
}

void MainWindow::on_ButtonInverseB_clicked() {
    setOperandB();
    CM->setResult((*CM->getOp2()).getRows(),(*CM->getOp2()).getColumns());
    CM->inverse(false);
    printResult();
}
