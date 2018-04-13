#include "../header/additionerror.h"

const char* AdditionError::what() const throw() {
    return "Non e' possibile sommare le matrici se non sono identiche";
}
