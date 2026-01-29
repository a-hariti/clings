#include <stdio.h>
#include "clings.h"

/*
 * Goal: Parse numbers using sscanf.
 *
 * sscanf returns the number of successfully parsed fields.
 */
int main(void) {
    const char *input = "12 34";
    int a = 0;
    int b = 0;
    int parsed = 0;

    // TODO: Parse two integers from input using sscanf.
    // parsed = sscanf(<input>, "<format>", <out1>, <out2>);

    check_int_msg(parsed, 2, "sscanf should parse two integers");
    check_int_msg(a, 12, "first number should be 12");
    check_int_msg(b, 34, "second number should be 34");

    return 0;
}
