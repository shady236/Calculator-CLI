#ifndef  _OPERATOR_H_
#define  _OPERATOR_H_


#include <math.h>
#include <stdbool.h>


typedef char Operator_t;

extern const Operator_t SUM;
extern const Operator_t SUB;
extern const Operator_t MUL;
extern const Operator_t DIV;
extern const Operator_t POW;


bool isValidOperator(Operator_t ch);
int operatorPriority(Operator_t op);
double opCalc(Operator_t op, double operand1, double operand2);



#endif   // _OPERATOR_H_