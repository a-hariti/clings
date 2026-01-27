#include <stdio.h>
#include "clings.h"

/*
 * Goal: Optimize struct layout.
 *
 * Compilers add padding between struct members to satisfy alignment
 * requirements. By reordering members, you can reduce the amount of
 * padding and the overall size of the struct.
 *
 * Generally, ordering members from largest to smallest type is a good
 * strategy to minimize padding.
 */

struct OptimizedMe {
    char a;
    long b;
    char c;
};

int main(void) {
    // On most 64-bit systems, the current layout takes 24 bytes.
    // Your goal is to reorder the members to reduce the size to 16 bytes.

    printf("Size of struct OptimizedMe: %zu\n", sizeof(struct OptimizedMe));

    // TODO: Reorder the members in 'struct OptimizedMe' so that the size is 16 bytes.
    check_int((int)sizeof(struct OptimizedMe), 16);

    return 0;
}