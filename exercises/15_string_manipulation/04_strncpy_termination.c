#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * strncpy does not always null-terminate when truncating.
 */

int main(void) {
    char buffer[5];

    strncpy(buffer, "hello", sizeof(buffer));

    // TODO: Ensure the buffer is always null-terminated.

    check_str_msg(buffer, "hell", "Buffer should contain a truncated string");

    return 0;
}
