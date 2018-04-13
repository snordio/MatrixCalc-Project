#include "../header/assignationerror.h"

const char* AssignationError::what() const throw() {
    return "Non e' possibile effettuare l'assegnazione, le dimensioni delle matrici devono essere uguali";
}
