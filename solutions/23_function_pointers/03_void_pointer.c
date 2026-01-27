#include <stdio.h>
#include "clings.h"

/*
 * void pointers (void*) are "generic pointers". They can point to any data type,
 * but they cannot be dereferenced directly because the compiler doesn't know
 * the size of the underlying data.
 *
 * To use them, you must cast them back to a specific pointer type.
 *
 * This is frequently used with function pointers to create generic functions
 * that can operate on different types of data.
 *
 * For further reading, check Beej's Guide:
 * https://beej.us/guide/bgc/html/split/pointers2.html#void-pointers
 */

// read this as: Modifier is a pointer to a function that takes a void pointer and returns void.
typedef void (*Modifier)(void *data);

void multiply_int_by_two(void *data) {
    int *pi = (int *)data;
    *pi *= 2;
}

void multiply_float_by_two(void *data) {
    float *pf = (float *)data;
    *pf *= 2.0f;
}

void apply_modifier(Modifier mod, void *data) {
    mod(data);
}

int main(void) {
    int i = 21;
    float f = 3.14f;

    apply_modifier(multiply_int_by_two, &i);
    apply_modifier(multiply_float_by_two, &f);

    check_int(i, 42);
    check_float(f, 6.28f);

    return 0;
}
