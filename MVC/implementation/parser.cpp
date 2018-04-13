#include "../header/parser.h"
#include "../../MODEL/header/complex.h"
#include "../../MODEL/header/rational.h"
#include "../../EXCEPTIONS/header/inputerror.h"

#include <QRegExp>
#include <QString>

Complex<Rational> Parser::stringToComplex(QString string) {
    int numReal=0, denReal=1, numIm=0, denIm=1;
    QRegExp re("^([-+]?\\d*)\\/?(\\d*)([-+]?\\d*)\\/?(\\d*)i?$");
    if (re.exactMatch(string)) {
        if(re.cap(1)!=0){
            numReal = re.cap(1).toInt();
            if(re.cap(2)!=0)
                denReal = re.cap(2).toInt();
        }
        if(re.cap(3)!=0){
            numIm = re.cap(3).toInt();
            if(re.cap(4)!=0)
                denIm = re.cap(4).toInt();
        }
        Rational real(numReal,denReal);
        Rational im(numIm, denIm);
        return Complex<Rational>(real,im);
    }
    throw InputError();
}


QString Parser::ComplexToString(Complex<Rational> complex) {
    Rational real = complex.getReal();
    Rational img = complex.getImg();
    QString string;
    string.append(QString::number(real.Numerator()));
    if(real.Numerator()!=0 && real.Denominator()!=1){
        string.append("/");
        string.append(QString::number(real.Denominator()));
    }
    if(img.Numerator()==0) return string;
    if(img.Numerator()>0) string.append("+");
    string.append(QString::number(img.Numerator()));
    if(img.Denominator()!=1){
        string.append("/");
        string.append(QString::number(img.Denominator()));
    }
    string.append("i");
    return string;
}
