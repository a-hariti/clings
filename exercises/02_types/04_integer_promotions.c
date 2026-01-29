#include <stdio.h>
#include "clings.h"

/*
 * Integer promotions happen automatically in expressions.
 * The promotion happens before the operation, but narrowing back to a smaller
 * type can still lose data.
 */

int main(void) {
    unsigned char a = 250;
    unsigned char b = 10;

    // TODO: Avoid narrowing so the sum keeps the full value.
    unsigned char sum = a + b;

    check_int_msg(sum, 260, "Sum should keep the full value");

    return 0;
}
