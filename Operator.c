#include "Operator.h"


const Operator_t SUM = '+';
const Operator_t SUB = '-';
const Operator_t MUL = '*';
const Operator_t DIV = '/';
const Operator_t POW = '^';
// const Operator_t* operators[] = {SUM, SUB, MUL, DIV, POW};


bool isValidOperator(Operator_t ch) {
    return ch == SUM || ch == SUB || ch == MUL || ch == DIV || ch == POW;
}

int operatorPriority(Operator_t op) {
    if (op == SUM || op == SUB) {
        return 1;
    }
    else if (op == MUL || op == DIV) {
        return 2;
    }        
    else if (op == POW) {
        return 3;
    }
    return -1;
}

double opCalc(Operator_t op, double operand1, double operand2) {
    if (op == SUM) {
        return operand1 + operand2;
    }
    else if (op == SUB) {
        return operand1 - operand2;
    }
    else if (op == MUL) {
        return operand1 * operand2;
    }
    else if (op == DIV) {
        return operand1 / operand2;
    }
    else if (op == POW) {
        return pow(operand1, operand2);
    }
}

