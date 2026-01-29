#include <stdio.h>
#include "clings.h"

/*
 * In C, returning a pointer to a local (stack) variable is undefined behavior.
 * When the function returns, its stack frame is reclaimed, and the memory
 * previously occupied by the local variable may be reused.
 *
 * Fix this function so it safely returns a pointer to the value 42.
 * Hint: You can use 'static' to make the variable persist after the function returns,
 * or allocate it on the heap, but you should probably allocate it on the heap.
 */

int *get_value(void) {
    int value = 42;
    return &value;
}

int main(void) {
    int *ptr = get_value();

    // Accessing a dangling pointer is undefined behavior!
    // ASan will likely catch this if the compiler doesn't stop us first.
    check_int_msg(*ptr, 42, "The pointer should point to the value 42");

    return 0;
}
