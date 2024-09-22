#ifndef  _STR_H_
#define  _STR_H_


#include <string.h>
#include <stdbool.h>
#include <ctype.h>


double parse(const char* const str, int* const endIdx);
void normalize(char* const str);



#endif   // _STR_H_