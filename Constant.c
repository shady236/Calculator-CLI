#include "Constant.h"


const char* E = "e";
const char* PI = "pi";


bool getConst(const char* const expression, const char** constName, double* constValue) {
    if (strncmp(expression, E, strlen(E)) == 0) {
        *constName = E;
        *constValue = exp(1);
        return true;
    }
    else if (strncmp(expression, PI, strlen(PI)) == 0) {
        *constName = PI;
        *constValue = M_PI;
        return true;
    }

    return false;
}
