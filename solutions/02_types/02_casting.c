#include <stdio.h>
#include "clings.h"

/*
 * Casting is used to convert one data type to another.
 * In C, dividing two integers results in integer division (the fractional part is discarded).
 * To get a floating-point result, at least one operand must be a floating-point type.
 */

int main(void) {
    int a = 5;
    int b = 2;

    /* Fixed: Cast 'a' and 'b' to float to ensure floating-point division */
    float result = (float)a / (float)b;

    check_float(result, 2.5f);

    return 0;
}