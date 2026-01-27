#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * C-lings: 10_double_pointers/01_modify_ptr.c
 *
 * When you want a function to modify a pointer in the caller's scope
 * (for example, to allocate memory and return it via a parameter),
 * you must pass a pointer to that pointer (a double pointer).
 *
 * Goal: Correct the function signature and implementation so that
 * 'ptr' in main is properly allocated and initialized.
 */

void allocate_int(int **p, int value) {
    if (p == NULL) {
        return;
    }
    *p = malloc(sizeof(int));
    if (*p != NULL) {
        **p = value;
    }
}

int main(void) {
    int *ptr = NULL;

    /* Fixed: Passed the address of the pointer (int **) */
    allocate_int(&ptr, 42);

    cling_assert(ptr != NULL, "ptr should be properly allocated on the heap");
    check_int(*ptr, 42);

    free(ptr);

    return 0;
}