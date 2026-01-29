#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    char buffer[5];

    strncpy(buffer, "hello", sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    check_str_msg(buffer, "hell", "Buffer should contain a truncated string");

    return 0;
}
