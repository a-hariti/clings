#include <stdio.h>
#include "clings.h"

/*
 * Functions in C must be declared before they are used.
 * You can either define the whole function before main, or
 * provide a 'prototype' (declaration) at the top.
 *
 * This file won't compile because 'add' is used in main
 * before the compiler knows it exists!
 */

int main(void) {
    /* TODO: Add the function prototype for 'add' above main! */
    int result = add(5, 10);

    check_int(result, 15);

    return 0;
}

int add(int a, int b) {
    return a + b;
}