#include "str.h"

double parse(const char* const str, int* const endIdx) {
    int i = 0;
    double sign = 1;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i++;
    }

    double val = 0;
    bool valid = false;
    while (str[i] >= '0' && str[i] <= '9') {
        val *= 10;
        val += str[i] - '0';
        i++;
        valid = true;
    }

    if (str[i] != '.') {
        if (valid) {
            *endIdx = i - 1;
        }
        else {
            *endIdx = -1;
        }

        return val * sign;
    }
    
    i++;
    double factor = 10;
    while (str[i] >= '0' && str[i] <= '9') {
        val += (str[i] - '0') / factor;
        factor *= 10;
        i++;
        valid = true;
    }

    if (valid) {
        *endIdx = i - 1;
    }
    else {
        *endIdx = -1;
    }
    return val * sign;
}

void normalize(char* const str) {
    int moveSteps = 0;
    int i = 0;
    
    while (str[i]) {
        if (str[i] == ' ') {
            moveSteps++;
        }
        else {
            str[i - moveSteps] = tolower(str[i]);
        }

        i++;
    }

    str[i - moveSteps] = '\0';
}
