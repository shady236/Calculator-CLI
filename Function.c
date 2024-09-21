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

double funcCalc(const char* const func, const double operand) {
    if (func == LOG) {
        return log(operand);
    }
    else if (func == ABS) {
        return abs(operand);
    }
    else if (func == FACT) {
        return fact(operand);
    }
    else if (func == SQRT) {
        return sqrt(operand);
    }
    else if (func == SIN) {
        return sin(operand * M_PI / 180);
    }
    else if (func == COS) {
        return cos(operand * M_PI / 180);
    }
    else if (func == TAN) {
        return tan(operand * M_PI / 180);
    }
}
