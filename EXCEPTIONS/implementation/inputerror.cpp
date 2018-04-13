#include "../header/inputerror.h"

const char* InputError::what() const throw() {
    return "I valori inseriti non sono validi";
}
