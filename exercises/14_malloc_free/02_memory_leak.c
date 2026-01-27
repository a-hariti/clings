#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/**
 * In C, every byte allocated with malloc() must be explicitly freed with free().
 * Failure to do so results in a 'memory leak', which can eventually consume
 * all available system memory.
 *
 * Goal: Free the allocated memory to avoid a leak!
 */

int main(void) {
    int *numbers = malloc(5 * sizeof(int));
    cling_assert(numbers != NULL, "Memory allocation failed");

    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }

    check_int(numbers[4], 40);

    /* TODO: The memory allocated for 'numbers' is never freed! */
    /* Add the missing free() call here and set it to NULL. */

    cling_assert(ACTIVE_ALLOCATIONS == 0, "No active allocations should remain");
    // it's a good practice to set pointers to NULL after freeing them
    cling_assert(numbers == NULL, "numbers pointer should be null");

    return 0;
}
