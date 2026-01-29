#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

int main(void) {
    int *numbers = malloc(5 * sizeof(int));
    cling_assert(numbers != NULL, "Memory allocation failed");

    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }

    check_int(numbers[4], 40);

    /* Free the allocated memory to avoid a leak */
    free(numbers);
    numbers = NULL;

    check_int_msg(ACTIVE_ALLOCATIONS, 0, "No active allocations should remain");
    // it's a good practice to set pointers to NULL after freeing them
    check_ptr_msg(numbers, NULL, "numbers pointer should be null");

    return 0;
}
