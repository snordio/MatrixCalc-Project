#include "../../MODEL/header/complex.h"
#include "../../EXCEPTIONS/header/complexerror.h"

template <class T>
Complex<T>::Complex(T r, T i) : real(r), img(i) {}

template <class T>
T Complex<T>::getReal() const {
    return real;
}

template <class T>
T Complex<T>::getImg() const {
    return img;
}

template <class T>
Complex<T>& Complex<T>::operator=(const Complex<T>& c) {
    if(this != &c){
        real = c.real;
        img = c.img;
    }
    return *this;
}

template <class T>
Complex<T>::Complex(const Complex<T>& c) : real(c.real), img(c.img) {}

template <class T>
Complex<T> Complex<T>::operator+(T a) const {
    return Complex(real + a, img);
}
template <class T>
Complex<T> Complex<T>::operator-(T a) const {
    return Complex(real - a, img);
}
template <class T>
Complex<T> Complex<T>::operator*(T a) const {
    return Complex(real * a, img * a);
}

template <class T>
Complex<T> Complex<T>::operator/(T a) const {
    if(a==T(0)) throw ComplexError();
    return Complex(real / a, img / a);
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex<T>& a) const {
    return Complex(real + a.real, img + a.img);
}

template <class T>
Complex<T> Complex<T>::operator-(const Complex<T>& a) const {
    return Complex(real - a.real, img - a.img);
}

template <class T>
Complex<T> Complex<T>::operator*(const Complex<T>& a) const {
    return Complex((real * a.real) - (img * a.img), (real * a.img) + (img * a.real));
}

template <class T>
Complex<T> Complex<T>::operator/(const Complex<T>& a) const {
    if(a==T(0)) throw ComplexError();
    return Complex( ((real * a.real) + (img * a.img)) / ((a.real * a.real) + (a.img * a.img)),
                    ((img * a.real) - (real * a.img)) / ((a.real * a.real) + (a.img * a.img)) );
}

template <class T>
Complex<T>& Complex<T>::operator+=(T a) {
    real += a;
    return *this;
}
template <class T>
Complex<T>& Complex<T>::operator-=(T a) {
    real -= a;
    return *this;
}
template <class T>
Complex<T>& Complex<T>::operator*=(T a) {
    real *= a;
    img *= a;
    return *this;
}
template <class T>
Complex<T>& Complex<T>::operator/=(T a) {
    if(a==T(0)) throw ComplexError();
    real /= a;
    img /= a;
    return *this;
}

template <class T>
Complex<T>& Complex<T>::operator+=(const Complex<T>& a) {
    real= real + a.real;
    img= img + a.img;
    return *this;
}

template <class T>
Complex<T>& Complex<T>::operator-=(const Complex<T>& a) {
    real= real - a.real;
    img= img - a.img;
    return *this;
}

template <class T>
Complex<T>& Complex<T>::operator*=(const Complex<T>& a) {
    T auxre = (real * a.real) - (img * a.img);
    T auxim = (real * a.img) + (img * a.real);
    real=auxre;
    img=auxim;
    return *this;
}

template <class T>
Complex<T>& Complex<T>::operator/=(const Complex<T>& a) {
    if(a==T(0)) throw ComplexError();
    T divider = ((a.getReal() * a.getReal()) + (a.getImg() * a.getImg()));
    T auxre= ((real * a.real) + (img * a.img)) /divider;
    T auxim= ((img * a.real) - (real * a.img)) / divider;
    real=auxre;
    img=auxim;
    return *this;
}

template<class T>
bool Complex<T>::operator==(const Complex<T>& a) const {
    return real == a.real && img == a.img;
}

template<class T>
bool Complex<T>::operator!=(const Complex<T>& a) const {
    return real != a.real || img != a.img;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
    if(c.img==T(0)) return os << c.real;
    if(c.img < T(0)) return os << c.real << c.img << "i";
    return os << c.real << "+" << c.img << "i";
}

template<class T>
std::istream& operator>>(std::istream& is, Complex<T>& c){
    return is >> c.real >> c.img;
}

