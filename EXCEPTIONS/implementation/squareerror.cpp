#include "../header/squareerror.h"

const char* SquareError::what() const throw() {
    return "Non e' possibile effettuare l'operazione richiesta su una matrice non quadrata";
}
