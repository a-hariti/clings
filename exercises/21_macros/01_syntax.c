#include <stdio.h>
#include "clings.h"

/*
 * Macros in C are simple text substitutions. This can lead to unexpected
 * results if operator precedence is not handled correctly.
 *
 * Your goal is to fix the SQUARE macro so it correctly calculates the square
 * of its argument, even if that argument is an expression.
 *
 * Hint: Think about how SQUARE(1 + 2) expands.
 */

// clang-format off
#define SQUARE(x) ((x) * (x))
// clang-format on

int main(void) {
    int x = 5;
    check_int(SQUARE(x), 25);

    /* This assertion will fail with the current macro definition */
    check_int(SQUARE(1 + 2), 9);

    return 0;
}
