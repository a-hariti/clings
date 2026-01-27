#include <stddef.h>
#include <stdio.h>
#include "clings.h"

/*
 * Goal: Calculate the distance between two pointers in the same array.
 *
 * Subtracting one pointer from another of the same type results in the
 * number of elements between them, not the number of bytes.
 * The result type is ptrdiff_t, which is a signed integer type.
 */

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int *start = &numbers[2]; // Points to 30
    int *end = &numbers[6];   // Points to 70

    // Calculate how many elements are between end and start.
    ptrdiff_t diff = end - start;

    check_int((int)diff, 4);

    return 0;
}
