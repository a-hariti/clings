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

    /* TODO: Fix the integer division bug so that result is 2.5 */
    /* Hint: You can use the cast operator: (float)variable */
    float result = a / b;

    check_float(result, 2.5f);

    return 0;
}