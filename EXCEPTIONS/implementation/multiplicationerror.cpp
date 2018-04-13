#include "../header/multiplicationerror.h"

const char* MultiplicationError::what() const throw() {
    return "Il numero di colonne della prima matrice deve essere uguale al numero di righe della seconda";
}
