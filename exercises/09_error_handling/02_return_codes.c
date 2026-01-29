#include <stdio.h>
#include "clings.h"

/*
 * Goal: Use return codes to signal errors.
 */
int parse_positive_int(const char *text, int *out) {
    // TODO: Parse a positive integer from text.
    // Return 0 on success, -1 on failure.
    return -1;
}

int main(void) {
    int value = 0;

    int ok = parse_positive_int("42", &value);
    check_int_msg(ok, 0, "Should parse a valid positive number");
    check_int_msg(value, 42, "Parsed value should be 42");

    ok = parse_positive_int("-3", &value);
    check_int_msg(ok, -1, "Negative numbers should fail");

    ok = parse_positive_int("abc", &value);
    check_int_msg(ok, -1, "Non-numeric input should fail");

    return 0;
}
