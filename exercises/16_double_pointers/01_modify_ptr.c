#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * When you want a function to modify a pointer in the caller's scope
 * (for example, to allocate memory and return it via a parameter),
 * you must pass a pointer to that pointer (a double pointer).
 *
 * Goal: Correct the function signature and implementation so that
 * 'ptr' in main is properly allocated and initialized.
 */

void allocate_int(int *p, int value) {
    p = malloc(sizeof(int));
    if (p != NULL) {
        *p = value;
    }
}

int main(void) {
    int *ptr = NULL;

    /* TODO: Modify the function above and this call to properly
     * allocate memory for 'ptr'.
     */
    allocate_int(ptr, 42);

    cling_assert(ptr != NULL, "ptr should not be NULL after allocation");
    check_int(*ptr, 42);

    free(ptr);

    return 0;
}