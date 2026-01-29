#include <stdio.h>
#include "clings.h"

/*
 * In C, returning a pointer to a local (stack) variable is undefined behavior.
 * When the function returns, its stack frame is reclaimed, and the memory
 * previously occupied by the local variable may be reused.
 *
 * Fix this function so it safely returns a pointer to the value 42.
 */

int *get_value(void) {
    // By allocating memory on the heap, the pointer returned will remain valid
    // even after the function returns.
    int *value = malloc(sizeof(int));
    if (!value) {
        return value;
    }
    *value = 42;
    return value;
}

int main(void) {
    int *ptr = get_value();

    check_int_msg(*ptr, 42, "The pointer should point to the value 42");

    free(ptr);
    ptr = NULL;

    return 0;
}
