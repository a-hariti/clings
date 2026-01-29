#include <stdio.h>
#include "clings.h"

/*
 * Goal: Avoid signed/unsigned comparison pitfalls.
 *
 * In C, when you compare a signed and an unsigned integer, the signed value
 * is converted to unsigned. That can produce surprising results.
 *
 * Fix the comparison so the result matches the intended logic.
 */
int main(void) {
    int s = -1;
    unsigned int u = 1;

    // TODO: Fix the comparison so -1 is considered less than 1.
    int is_less = (s < u);

    check_int_msg(is_less, 1, "-1 should be less than 1 with a correct comparison");

    return 0;
}
