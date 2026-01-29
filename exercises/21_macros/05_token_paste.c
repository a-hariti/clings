#include <stdio.h>
#include "clings.h"

/*
 * Token pasting lets you build identifiers from pieces.
 */

// TODO: Implement JOIN so JOIN(value_, 1) becomes value_1.
// #define JOIN(a, b) ...

int main(void) {
    int value_1 = 7;

    int result = JOIN(value_, 1);

    check_int_msg(result, 7, "JOIN should build the identifier value_1");

    return 0;
}
