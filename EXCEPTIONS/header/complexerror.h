#ifndef COMPLEXERROR_H
#define COMPLEXERROR_H

#include<stdexcept>

class ComplexError : public std::exception {
public:
    const char* what() const throw();
};

#endif // COMPLEXERROR_H
