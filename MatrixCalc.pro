QT += gui
QT += widgets

CONFIG += c++11
CONFIG -= console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    MVC/implementation/modelmatrix.cpp \
    MVC/implementation/controllermatrix.cpp \
	MVC/implementation/mainwindow.cpp \
    MVC/implementation/parser.cpp \
    MODEL/implementation/matrix.cpp \
    MODEL/implementation/squarematrix.cpp \
    MODEL/implementation/nonsquarematrix.cpp \
	MODEL/implementation/rational.cpp \
	MODEL/implementation/complex.cpp \
    EXCEPTIONS/implementation/matrixerror.cpp \
    EXCEPTIONS/implementation/multiplicationerror.cpp \
    EXCEPTIONS/implementation/outofrangeerror.cpp \
    EXCEPTIONS/implementation/inverseerror.cpp \   
    EXCEPTIONS/implementation/rationalerror.cpp \
    EXCEPTIONS/implementation/additionerror.cpp \
    EXCEPTIONS/implementation/subtractionerror.cpp \   
    EXCEPTIONS/implementation/complexerror.cpp \
    EXCEPTIONS/implementation/assignationerror.cpp \
    EXCEPTIONS/implementation/squareerror.cpp \
    EXCEPTIONS/implementation/inputerror.cpp

HEADERS += \
    MVC/header/modelmatrix.h \
    MVC/header/controllermatrix.h \
	MVC/header/mainwindow.h \
    MVC/header/parser.h \
    MODEL/header/matrix.h \
    MODEL/header/squarematrix.h \
    MODEL/header/nonsquarematrix.h \
	MODEL/header/rational.h \
	MODEL/header/complex.h \
    EXCEPTIONS/header/matrixerror.h \
    EXCEPTIONS/header/multiplicationerror.h \
    EXCEPTIONS/header/outofrangeerror.h \
    EXCEPTIONS/header/inverseerror.h \
    EXCEPTIONS/header/rationalerror.h \
    EXCEPTIONS/header/additionerror.h \
    EXCEPTIONS/header/subtractionerror.h \
    EXCEPTIONS/header/complexerror.h \
    EXCEPTIONS/header/assignationerror.h \
    EXCEPTIONS/header/squareerror.h \
    EXCEPTIONS/header/inputerror.h

FORMS += \
    MVC/mainwindow.ui

RESOURCES += \
    resource.qrc
