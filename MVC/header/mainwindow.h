#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QRadioButton>
#include <QCloseEvent>
#include "controllermatrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    ControllerMatrix* CM;
    void configureComponents();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setValuesA(unsigned int, unsigned int);
    void setValuesB(unsigned int, unsigned int);
    void setOperandA();
    void setOperandB();
    void printResult();
    void setZero(bool);
    void closeEvent(QCloseEvent*);

private slots:
    void on_spinBoxRowsA_valueChanged(int);
    void on_spinBoxColumnsA_valueChanged(int);
    void on_spinBoxRowsB_valueChanged(int);
    void on_spinBoxColumnsB_valueChanged(int);
    void on_ButtonMult_clicked();
    void on_ButtonAdd_clicked();
    void on_ButtonSub_clicked();
    void on_ButtonMultScalarA_clicked();
    void on_ButtonMultScalarB_clicked();
    void on_ButtonTransA_clicked();
    void on_ButtonTransB_clicked();
    void on_ButtonTraceA_clicked();
    void on_ButtonTraceB_clicked();
    void on_ButtonGaussA_clicked();
    void on_ButtonGaussB_clicked();
    void on_ButtonDeterminantA_clicked();
    void on_ButtonDeterminantB_clicked();
    void on_ButtonRankA_clicked();
    void on_ButtonRankB_clicked();
    void on_ButtonInverseA_clicked();
    void on_ButtonInverseB_clicked();
};

#endif // MAINWINDOW_H
