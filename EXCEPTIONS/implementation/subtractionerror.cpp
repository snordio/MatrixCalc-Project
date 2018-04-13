#include "../header/subtractionerror.h"

const char* SubtractionError::what() const throw() {
    return "Non e' possibile sottrarre le matrici se non sono identiche";
}
