#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>

class Rational{
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);
private:
    long long int num;
    long long int den;
    void Normalize();
    void Simplify();
public:
    Rational(long long int =0,long long int =1);
    Rational(const Rational&);
    Rational& operator=(const Rational&);
    ~Rational(){}
    long long int Numerator();
    long long int Denominator();
    operator double() const;
    Rational operator+(const Rational&) const;
    Rational& operator+=(const Rational&);
    Rational operator+(int) const;
    Rational operator*(const Rational&) const;
    Rational& operator*=(const Rational&);
    Rational operator*(int) const;
    Rational operator-(const Rational&) const;
    Rational& operator-=(const Rational&);
    Rational operator-(int) const;
    Rational operator/(const Rational&) const;
    Rational& operator/=(const Rational&);
    Rational operator/(int) const;
    bool operator<(const Rational&) const;
    bool operator==(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator!=(const Rational&) const;
    static long long int MCD(long long int,long long int);
};

#endif // RATIONAL_H
