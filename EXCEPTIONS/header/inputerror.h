#ifndef INPUTERROR_H
#define INPUTERROR_H

#include<stdexcept>

class InputError : public std::exception {
public:
    const char* what() const throw();
};

#endif // INPUTERROR_H
