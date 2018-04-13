#include "../header/outofrangeerror.h"

const char* OutOfRangeError::what() const throw() {
    return "L'elemento in posizione richiesta non esiste";
}
