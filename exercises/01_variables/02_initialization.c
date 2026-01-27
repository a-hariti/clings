#include <stdio.h>
#include "clings.h"

/*
 * In C, local variables are not automatically initialized to zero.
 * They contain "garbage values" from whatever was previously at that memory location.
 * Using an uninitialized variable is Undefined Behavior.
 *
 * Goal: Initialize `x` so that it passes the assertion.
 */

int main(void) {
    int x;

    check_int(x, 42);

    return 0;
}