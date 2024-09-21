#include <stdio.h>
#include <stdbool.h>
#include "Calculator.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        perror("Invalid Usage, correct usage: ./calc <expression>\n");
        perror("Note: if <expression> has spaces, enclose it in double quotes \"\"\n");
        return -1;
    }

    char* expression = argv[1];
    double result;
    if (calc(expression, &result)) {
        printf("%s = %lf\n", expression, result);
    }
    else {
        printf("%s not valid or too long\n", expression);
    }
}