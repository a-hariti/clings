#include <stdio.h>
#include "clings.h"

/*
 * In C, a semicolon immediately after a for loop header
 * creates an empty loop body. This can lead to unexpected
 * results or scope errors if you try to use the loop
 * variable afterwards.
 *
 * Fix the loop so that the sum is calculated correctly.
 */

int main(void) {
    int sum = 0;

    // TODO: Fix the loop scope so the block below is executed 5 times
    // clang-format off
    for (int i = 0; i < 5; i++);
    {
        sum += i;
    }
    // clang-format on

    check_int(sum, 10); // 0 + 1 + 2 + 3 + 4 = 10

    return 0;
}
