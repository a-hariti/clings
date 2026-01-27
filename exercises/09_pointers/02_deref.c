#include <stdio.h>
#include "clings.h"

/*
 * C-lings: 05_pointers/02_deref.c
 *
 * To access or modify the value stored at a memory address held by a pointer,
 * use the dereference operator (*).
 *
 * Goal: Use the pointer `p` to change the value of `n` to 100.
 */

int main(void) {
    int n = 42;
    int *p = &n;

    // TODO: Use the pointer `p` to change the value of `n` to 100.
    // Hint: You need to dereference `p` to access the value it points to.
    p = 100;

    check_int(n, 100);

    return 0;
}