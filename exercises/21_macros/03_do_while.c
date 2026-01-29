#include <stdio.h>
#include "clings.h"

/*
 * Goal: Make a macro behave like a single statement.
 *
 * Fix the macro by wrapping it in do { ... } while (0).
 */
#define ADD_IF_POSITIVE(x, y)                                                                                          \
    if ((y) > 0)                                                                                                       \
        (x) += (y);

int main(void) {
    int x = 0;
    int y = 1;
    int flag = 0;

    if (flag)
        ADD_IF_POSITIVE(x, y);
    else
        x = 5;

    check_int_msg(x, 5, "x should be set by the else branch");

    return 0;
}
