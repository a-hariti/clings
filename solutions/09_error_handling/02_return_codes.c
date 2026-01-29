#include <stdio.h>
#include "clings.h"

int parse_positive_int(const char *text, int *out) {
    int value = 0;
    if (sscanf(text, "%d", &value) != 1) {
        return -1;
    }
    if (value <= 0) {
        return -1;
    }
    *out = value;
    return 0;
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
