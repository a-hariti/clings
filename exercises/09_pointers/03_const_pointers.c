#include <stdio.h>
#include "clings.h"

/**
 * Understand the difference between:
 * 1. Pointer to constant: const int *ptr (or int const *ptr)
 *    - The data it points to is constant.
 * 2. Constant pointer: int *const ptr
 *    - The pointer itself is constant (it cannot point elsewhere).
 *
 * Task: Comment out the lines that cause compiler errors.
 */

int main(void) {
    int a = 10;
    int b = 20;

    // ptr1 is a pointer to constant int
    const int *ptr1 = &a;
    *ptr1 = 15; // This should be a compiler error
    check_int(*ptr1, 10);
    ptr1 = &b; // This is allowed

    // ptr2 is a constant pointer to int
    int *const ptr2 = &a;
    *ptr2 = 15; // This is allowed
    ptr2 = &b;  // This should be a compiler error

    check_int(a, 15);
    check_int(*ptr1, 20);

    return 0;
}
