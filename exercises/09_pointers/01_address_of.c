#include <stdio.h>
#include "clings.h"

/*
 * A pointer is a variable that stores the memory address of another variable.
 * To get the address of a variable, use the address-of operator (&).
 *
 * Goal: Assign the address of `n` to the pointer `p`.
 */

int main(void) {
    int n = 42;
    // TODO: Assign the address of n to p
    // Hint: Currently we are trying to assign an integer value directly
    // to a pointer, which will cause a compiler error.
    int *p = n;

    cling_assert(p == &n, "p should point to n");
    check_int(*p, 42);

    return 0;
}