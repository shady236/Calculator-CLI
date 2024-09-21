#include "Calculator.h"


// Calculate the expression enclosed in parentheses () and maybe followed by any expressions after the parentheses.
static double enclosedCalc(const char* const expression, int* const endIdx);


static void printDouble(const void* const data) {
    printf("%lf", *((double*)data));
}

static void printOp(const void* const data) {
    printf("%c", *((Operator_t*)data));
}


bool calc(const char* const expression, double* const res) {
    char* enclosedExpression = malloc(strlen(expression) + 3);
    strcpy(enclosedExpression, "(");
    strcat(enclosedExpression, expression);
    strcat(enclosedExpression, ")");
    removeSpaces(enclosedExpression);
    
    int endIdx = -1;
    *res = enclosedCalc(enclosedExpression, &endIdx);

    return (endIdx == strlen(enclosedExpression) - 1);
}


static double enclosedCalc(const char* const expression, int* const endIdx) {
    Stack_t vals;
    Stack_t ops;
    
    if (Stack_Init(&vals, 10, sizeof(double), printDouble) == false) {
        *endIdx = -1;
        return 0;
    }
    if (Stack_Init(&ops, 10, sizeof(Operator_t), printOp) == false) {
        *endIdx = -1;
        return 0;
    }

    int numNotClosedBrackets = 0;
    bool isPrevTokenNum = false;

    double e  = exp(1);
    double pi = M_PI;

    int i = 0;
    while (expression[i]) {
        if (expression[i] == 'e') {
            if (isPrevTokenNum) {
                Stack_Push(&ops, &MUL);
            }
            isPrevTokenNum = true;

            Stack_Push(&vals, &e);
            i++;
        }
        else if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
            if (isPrevTokenNum) {
                Stack_Push(&ops, &MUL);
            }
            isPrevTokenNum = true;

            int j;
            double val = parse(expression + i, &j);
            if (j == -1) {
                *endIdx = -1;
                break;
            }

            Stack_Push(&vals, &val);
            i += j + 1;
        }
        else if (expression[i] == '(') {
            if (isPrevTokenNum) {
                Stack_Push(&ops, &MUL);
            }
            isPrevTokenNum = false;

            numNotClosedBrackets++;
            Stack_Push(&ops, &expression[i]);
            i++;
        }
        else if (expression[i] == ')') {
            isPrevTokenNum = true;
            
            if (numNotClosedBrackets == 0) {
                *endIdx = -1;
                break;
            }

            numNotClosedBrackets--;
            while (!Stack_IsEmpty(&ops)) {
                Operator_t op;
                Stack_Pop(&ops, &op);
                
                if (op == '(') {
                    break;
                }

                double val1, val2;
                Stack_Pop(&vals, &val2);
                Stack_Pop(&vals, &val1);
                double opRes = opCalc(op, val1, val2);
                Stack_Push(&vals, &opRes);
            }

            if (numNotClosedBrackets == 0) {
                *endIdx = i;
                break;
            }

            i++;
        }
        else if (isValidOperator(expression[i])) {
            if (!isPrevTokenNum) {
                int j;
                double val = parse(expression + i, &j);
                if (j == -1) {
                    *endIdx = -1;
                    break;
                }

                Stack_Push(&vals, &val);
                isPrevTokenNum = true;
                i += j;
                continue;
            }
            isPrevTokenNum = false;
            
            while (!Stack_IsEmpty(&ops)) {
                Operator_t op;
                Stack_Peek(&ops, &op);
                if (op == '(' || operatorPriority(op) < operatorPriority(expression[i])) {
                    break;
                }

                Stack_Pop(&ops, &op);
                double val1, val2;
                Stack_Pop(&vals, &val2);
                Stack_Pop(&vals, &val1);
                double opRes = opCalc(op, val1, val2);
                Stack_Push(&vals, &opRes);
            }

            Stack_Push(&ops, &expression[i]);
            i++;
        }
        else {
            if (isPrevTokenNum) {
                Stack_Push(&ops, &MUL);
            }
            isPrevTokenNum = true;
            
            const char* func = getFunc(expression + i);
            if (func == NULL) {
                *endIdx = -1;
                break;;
            }

            int funcLen = strlen(func);
            if (expression[i + funcLen] != '(') {
                *endIdx = -1;
                break;
            }

            int j;
            double param = enclosedCalc(expression + i + funcLen, &j);
            if (j == -1) {
                *endIdx = -1;
                break;
            }

            double funcRes = funcCalc(func, param);
            Stack_Push(&vals, &funcRes);
            i += funcLen + j + 1;
        }
    }
    
    double res;
    Stack_Peek(&vals, &res);
    Stack_Free(&vals);
    Stack_Free(&ops);
    return res;
}
