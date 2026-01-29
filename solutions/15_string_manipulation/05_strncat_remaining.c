#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    char buffer[8] = "Hi ";
    const char *name = "Bob";

    size_t remaining = sizeof(buffer) - strlen(buffer) - 1;
    strncat(buffer, name, remaining);

    check_str_msg(buffer, "Hi Bob", "Buffer should contain the full name");

    return 0;
}
