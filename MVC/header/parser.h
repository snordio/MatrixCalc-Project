#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include "../../MODEL/header/complex.h"
#include "../../MODEL/header/rational.h"

class Parser {
public:
    static Complex<Rational> stringToComplex(QString);
    static QString ComplexToString(Complex<Rational>);
};

#endif // PARSER_H
