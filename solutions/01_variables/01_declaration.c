#include <stdio.h>
#include "clings.h"

/*
 * In C, every variable must be declared with a type before it can be used.
 * Declarations tell the compiler how much memory to allocate and how to
 * interpret the bits stored in that memory.
 *
 * This exercise uses a variable 'x' that hasn't been declared yet.
 * Fix it by adding 'int' before the first use of 'x'.
 */

int main(void) {
    int x = 42;

    check_int(x, 42);

    return 0;
}
