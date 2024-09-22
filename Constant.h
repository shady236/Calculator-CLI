#ifndef  _CONSTANT_H_
#define  _CONSTANT_H_


#include <math.h>
#include <stdbool.h>
#include <string.h>



extern const char* E;
extern const char* PI;


bool getConst(const char* const expression, const char** constName, double* constValue);



#endif   // _CONSTANT_H_