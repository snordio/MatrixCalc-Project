#include "../../MODEL/header/rational.h"
#include "../../EXCEPTIONS/header/rationalerror.h"

Rational::Rational(long long int n,long long int d) : num(n), den(d) {
    if(den==0) {
        num=0; den=1;
        throw RationalError();
    }
    else
        Normalize();
    Simplify();
}

Rational::Rational(const Rational& a): num(a.num), den(a.den){}

void Rational::Normalize() {
    if(den<0) {
        num=-num;
        den=-den;
    }
}

void Rational::Simplify() {
    if (num == 0) den = 1;
    else {
        long long int mcd = MCD(num, den);
        num=num/mcd;
        den=den/mcd;
        Normalize();
    }
}

long long int Rational::Numerator() {
    return num;
}

long long int Rational::Denominator() {
    return den;
}

Rational::operator double() const {
    return static_cast<double>(num)/static_cast<double>(den);
}

Rational& Rational::operator=(const Rational& r) {
    if (this != &r) {
        num = r.num;
        den = r.den;
    }
    return *this;
}

Rational Rational::operator+(const Rational &a) const {
    return Rational(num*a.den + den*a.num, den*a.den);
}

Rational& Rational::operator+=(const Rational &a) {
    num= num*a.den + den*a.num;
    den= den*a.den;
    return *this;
}

Rational Rational::operator+(int x) const {
    return Rational(num+x*den,den);
}

Rational Rational::operator*(const Rational &a) const {
    return Rational(num*a.num, den*a.den);
}

Rational& Rational::operator*=(const Rational &a) {
    num=num*a.num;
    den=den*a.den;
    return *this;
}

Rational Rational::operator*(int x) const {
    return Rational(num*x,den);
}

Rational Rational::operator-(const Rational& a) const {
    return Rational(num*a.den - den*a.num, den*a.den);
}

Rational& Rational::operator-=(const Rational &a) {
    num= num*a.den - den*a.num;
    den= den*a.den;
    return *this;
}


Rational Rational::operator-(int x) const {
    return Rational(num-den*x, den);
}

Rational Rational::operator/(const Rational& a) const {
    if(!a.num) throw RationalError();
    return Rational(num*a.den,den*a.num);
}

Rational& Rational::operator/=(const Rational &a) {
    if(!a.num) throw RationalError();
    num= num*a.den;
    den= den*a.num;
    return *this;
}

Rational Rational::operator/(int x) const {
    if(!x) throw RationalError();
    return Rational(num,den*x);
}

bool Rational::operator<(const Rational &a) const {
    return num*a.den < a.num*den;
}

bool Rational::operator==(const Rational &a) const {
    return num*a.den == a.num*den;
}

bool Rational::operator>(const Rational &a) const {
    return num*a.den > a.num*den;
}

bool Rational::operator<=(const Rational &a) const {
    return num*a.den <= a.num*den;
}

bool Rational::operator>=(const Rational &a) const {
    return num*a.den >= a.num*den;
}

bool Rational::operator!=(const Rational &a) const {
    return num*a.den != a.num*den;
}

std::ostream &operator<<(std::ostream &out, const Rational &a) {
    if(!a.num || a.den==1) return out << a.num;
    return out << a.num << "/" << a.den;
}

std::istream& operator>>(std::istream &in, Rational &a) {
    return in >> a.num >> a.den;
}

long long int Rational::MCD(long long int n,long long int d) {
    long long int temp;
    while (d != 0) {
        temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}
