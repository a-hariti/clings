#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/**
 * In C, if you want to use memory on the heap, you must explicitly allocate it.
 * The malloc() function is used to allocate a specified number of bytes.
 *
 * Goal: Allocate enough memory for an integer using malloc.
 */

int main(void) {
    int *ptr = NULL;

    /* TODO: Allocate memory for an integer using malloc */
    /* Hint: malloc(sizeof(int)) */

    cling_assert(ptr != NULL, "ptr should not be NULL");
    *ptr = 42;

    check_int(*ptr, 42);

    /* TODO: Don't forget to free what you allocate! */

    check_int_msg(ACTIVE_ALLOCATIONS, 0, "No active allocations should remain");
    return 0;
}
