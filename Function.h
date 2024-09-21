#ifndef  _FUNCTION_H_
#define  _FUNCTION_H_


#include <stdlib.h>
#include <math.h>
#include <string.h>


extern const char* LOG;
extern const char* ABS;
extern const char* FACT;
extern const char* SQRT;
extern const char* SIN;
extern const char* COS;
extern const char* TAN;


char* getFunc(const char* const expression);
double funcCalc(const char* const func, const double operand);


#endif   // _FUNCTION_H_