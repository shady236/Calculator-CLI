#ifndef  _FUNCTION_H_
#define  _FUNCTION_H_


#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


extern const char* LOG;
extern const char* ABS;
extern const char* FACT;
extern const char* SQRT;
extern const char* SIN;
extern const char* COS;
extern const char* TAN;


char* getFunc(const char* const expression);
bool funcCalc(const char* const func, const double operand, double* const res);


#endif   // _FUNCTION_H_