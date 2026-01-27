#include <stdio.h>
#include "clings.h"

/*
 * Functions in C must be declared before they are used.
 * You can either define the whole function before main, or
 * provide a 'prototype' (declaration) at the top.
 */

/* Function prototype */
int add(int a, int b);

int main(void) {
    int result = add(5, 10);

    check_int(result, 15);

    return 0;
}

int add(int a, int b) {
    return a + b;
}