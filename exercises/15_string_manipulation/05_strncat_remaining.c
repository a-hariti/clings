#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * strncat appends at most N characters and always writes a null terminator.
 * You must pass the remaining space, not the total buffer size.
 */

int main(void) {
    char buffer[8] = "Hi ";
    const char *name = "Bob";

    // TODO: Append using the remaining space in buffer.
    // strncat(buffer, name, <remaining>);

    check_str_msg(buffer, "Hi Bob", "Buffer should contain the full name");

    return 0;
}
