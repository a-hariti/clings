#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * Goal: Use calloc to allocate zero-initialized memory.
 */
int main(void) {
    size_t count = 4;
    int *numbers = NULL;

    // TODO: Allocate using calloc so numbers are zero-initialized.
    // numbers = calloc(<count>, <size>);

    cling_assert(numbers != NULL, "Allocation should succeed");

    for (size_t i = 0; i < count; i++) {
        check_int_msg(numbers[i], 0, "calloc should zero-initialize memory");
    }

    free(numbers);
    return 0;
}
