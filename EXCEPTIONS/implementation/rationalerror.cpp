#include "../header/rationalerror.h"

const char* RationalError::what() const throw() {
    return "Non e' possibile dividere per 0";
}
