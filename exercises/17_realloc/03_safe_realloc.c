#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * Goal: Reallocate memory safely using a temporary pointer.
 */
int main(void) {
    int *numbers = malloc(2 * sizeof(int));
    cling_assert(numbers != NULL, "Initial allocation should succeed");
    numbers[0] = 1;
    numbers[1] = 2;

    int *tmp = NULL;
    // TODO: Reallocate to hold 4 ints using a temporary pointer.
    // tmp = realloc(numbers, 4 * sizeof(int));
    // if (tmp == NULL) { free(numbers); return 1; }
    // numbers = tmp;

    numbers[2] = 3;
    numbers[3] = 4;

    check_int_msg(numbers[0], 1, "Value 1 should be preserved");
    check_int_msg(numbers[1], 2, "Value 2 should be preserved");
    check_int_msg(numbers[2], 3, "Value 3 should be set");
    check_int_msg(numbers[3], 4, "Value 4 should be set");

    free(numbers);
    return 0;
}
