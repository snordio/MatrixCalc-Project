#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>

template<class T>
class Complex;

template<class T>
std::ostream& operator<<(std::ostream&, const Complex<T>&);

template<class T>
std::istream& operator>>(std::istream&, Complex<T>&);

template<class T =double>
class Complex {
private:
    T real, img;
public:
    friend std::ostream& operator<< <>(std::ostream&, const Complex<T>&);
    friend std::istream& operator>> <>(std::istream&, Complex<T>&);
    Complex(T =0,T =0);
    Complex(const Complex<T>&);
    T getReal() const;
    T getImg() const;
    Complex<T>& operator=(const Complex<T>&);
    Complex<T> operator+(T a) const;
    Complex<T> operator-(T a) const;
    Complex<T> operator*(T a) const;
    Complex<T> operator/(T a) const;
    Complex<T> operator+(const Complex<T>&) const;
    Complex<T> operator-(const Complex<T>&) const;
    Complex<T> operator*(const Complex<T>&) const;
    Complex<T> operator/(const Complex<T>&) const;
    Complex<T>& operator+=(T);
    Complex<T>& operator-=(T);
    Complex<T>& operator*=(T);
    Complex<T>& operator/=(T);
    Complex<T>& operator+=(const Complex<T>&);
    Complex<T>& operator-=(const Complex<T>&);
    Complex<T>& operator*=(const Complex<T>&);
    Complex<T>& operator/=(const Complex<T>&);
    bool operator==(const Complex<T>&) const;
    bool operator!=(const Complex<T>&) const;
};

#include "../implementation/complex.cpp"

#endif // COMPLEX_H
