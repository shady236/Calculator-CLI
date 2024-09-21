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


bool isValidOperator(const Operator_t ch);
int operatorPriority(const Operator_t op);
bool opCalc(const Operator_t op, const double operand1, const double operand2, double* const res);



#endif   // _OPERATOR_H_