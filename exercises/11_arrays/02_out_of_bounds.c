#include <stdio.h>
#include "clings.h"

/*
 * Fix the off-by-one error.
 * In C, array indexing starts at 0 and goes up to length - 1.
 * Accessing an index outside this range is undefined behavior.
 *
 * Task: Modify the loop condition so it doesn't access the array out of bounds.
 */

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int length = 5;
    int sum = 0;

    /* BUG: The loop goes from 0 to 5, but the last valid index is 4! */
    for (int i = 0; i <= length; i++) {
        sum += numbers[i];
    }

    /* We expect the sum of 1+2+3+4+5 = 15 */
    check_int(sum, 15);

    return 0;
}