#include "Function.h"


const char* LOG = "log";
const char* ABS = "abs";
const char* FACT = "fact";
const char* SQRT = "sqrt";
const char* SIN = "sin";
const char* COS = "cos";
const char* TAN = "tan";
static const char** (funcs[]) = {&LOG, &ABS, &FACT, &SQRT, &SIN, &COS, &TAN};


static long long fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

char* getFunc(const char* const expression) {
    int numFuncs = sizeof(funcs) / sizeof(funcs[0]);
    for (int i = 0; i < numFuncs; i++) {
        if (strncmp(expression, *funcs[i], strlen(*funcs[i]))  == 0) {
            return *funcs[i];
        }
    }
    return NULL;
}

bool funcCalc(const char* const func, const double operand, double* const res) {
    if (func == LOG) {
        if (operand == 0) {
            return false;
        }

        *res = log(operand);
    }
    else if (func == ABS) {
        *res = abs(operand);
    }
    else if (func == FACT) {
        if (operand < 0 || ((double) ((int) operand)) != operand) {
            return false;
        }
        
        *res = fact(operand);
    }
    else if (func == SQRT) {
        if (operand < 0) {
            return false;
        }

        *res = sqrt(operand);
    }
    else if (func == SIN) {
        *res = sin(operand * M_PI / 180);
    }
    else if (func == COS) {
        *res = cos(operand * M_PI / 180);
    }
    else if (func == TAN) {
        *res = tan(operand * M_PI / 180);
    }

    return true;
}
