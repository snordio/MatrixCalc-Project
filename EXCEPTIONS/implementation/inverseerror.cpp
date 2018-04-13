#include "../header/inverseerror.h"

const char* InverseError::what() const throw() {
    return "Non e' possibile calcolare l'inversa di una matrice singolare";
}

