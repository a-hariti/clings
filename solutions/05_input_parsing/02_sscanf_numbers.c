#include <stdio.h>
#include "clings.h"

int main(void) {
    const char *input = "12 34";
    int a = 0;
    int b = 0;
    int parsed = 0;

    parsed = sscanf(input, "%d %d", &a, &b);

    check_int_msg(parsed, 2, "sscanf should parse two integers");
    check_int_msg(a, 12, "first number should be 12");
    check_int_msg(b, 34, "second number should be 34");

    return 0;
}
