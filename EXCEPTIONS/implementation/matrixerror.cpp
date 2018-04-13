#include "../header/matrixerror.h"

const char* MatrixError::what() const throw() {
    return "Si e' verificato un errore imprevisto";
}
