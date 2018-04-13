#include "../header/complexerror.h"

const char* ComplexError::what() const throw() {
    return "Non e' possibile dividere per 0";
}
