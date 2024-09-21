#include "Operator.h"


const Operator_t SUM = '+';
const Operator_t SUB = '-';
const Operator_t MUL = '*';
const Operator_t DIV = '/';
const Operator_t POW = '^';


bool isValidOperator(const Operator_t ch) {
    return ch == SUM || ch == SUB || ch == MUL || ch == DIV || ch == POW;
}

int operatorPriority(const Operator_t op) {
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

bool opCalc(const Operator_t op, const double operand1, const double operand2, double* const res) {
    if (op == SUM) {
        *res = operand1 + operand2;
    }
    else if (op == SUB) {
        *res = operand1 - operand2;
    }
    else if (op == MUL) {
        *res = operand1 * operand2;
    }
    else if (op == DIV) {
        if (operand2 == 0) {
            return false;
        }

        *res = operand1 / operand2;
    }
    else if (op == POW) {
        *res = pow(operand1, operand2);
    }

    return true;
}

