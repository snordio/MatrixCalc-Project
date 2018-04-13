#ifndef RATIONALERROR_H
#define RATIONALERROR_H

#include<stdexcept>

class RationalError : public std::exception {
public:
    const char* what() const throw();
};

#endif // RATIONALERROR_H
