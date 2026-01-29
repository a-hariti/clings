#include <stdio.h>
#include "clings.h"

/*
 * Unions allow different data types to share the same memory location.
 * The size of a union is the size of its largest member.
 * Modifying one member of a union will affect the others.
 */

typedef union {
    int i;
    float f;
} Number;

int main(void) {
    Number n;

    n.i = 42;
    check_int(n.i, 42);

    /*
     * Setting n.f will overwrite the memory used by n.i.
     * In a struct, n.i and n.f would have separate addresses.
     */
    n.f = 1.0f;
    check_float(n.f, 1.0f);

    /*
     * After setting n.f, n.i no longer holds the value 42.
     * It now holds the integer representation of the bit pattern for 1.0f (0x3f800000).
     */
    cling_assert(n.i != 42, "Union members share the same memory; modifying one affects the others");

    return 0;
}