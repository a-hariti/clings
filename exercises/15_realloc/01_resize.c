#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/**
 * realloc() can move the memory block to a new location.
 * When this happens, the old pointer becomes invalid.
 * Always assign the return value of realloc() back to your pointer (or a temporary pointer).
 *
 * The compiler will often warn you if you ignore the return value of realloc().
 */

int main(void) {
    int *numbers = malloc(2 * sizeof(int));
    if (numbers == NULL) {
        return 1;
    }

    numbers[0] = 10;
    numbers[1] = 20;

    // TODO: Resize the array to hold 4 integers.
    // Why is this call to realloc() insufficient?
    realloc(numbers, 4 * sizeof(int));

    // After realloc, we want to add two more numbers
    numbers[2] = 30;
    numbers[3] = 40;

    check_int(numbers[0], 10);
    check_int(numbers[1], 20);
    check_int(numbers[2], 30);
    check_int(numbers[3], 40);

    free(numbers);

    return 0;
}