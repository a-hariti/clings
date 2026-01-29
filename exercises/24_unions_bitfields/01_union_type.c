#include <stdio.h>
#include "clings.h"

/*
 * A union is a special data type that allows storing different data types
 * in the same memory location. All members share the same space.
 *
 * Your task is to change the 'Number' definition so that 'i' and 'f'
 * share the same memory. Currently, it's defined as a 'struct',
 * meaning they have separate memory.
 */

typedef struct {
    int i;
    float f;
} Number;

int main(void) {
    Number n;

    n.i = 42;
    check_int(n.i, 42);

    /*
     * If Number is a union, setting n.f will overwrite the memory used by n.i.
     */
    n.f = 1.0f;
    check_float(n.f, 1.0f);

    /*
     * This assertion will fail if 'Number' is still a 'struct'
     * because n.i will still be 42.
     */
    cling_assert(n.i != 42, "Union members share the same memory; modifying one affects the others");

    return 0;
}