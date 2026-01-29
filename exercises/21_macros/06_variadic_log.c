#include <stdio.h>
#include "clings.h"

/*
 * Variadic macros can forward optional arguments.
 * Use __VA_OPT__(,) so the macro works with or without extra args.
 */

// TODO: Implement LOG to prefix with "[LOG] ".
// #define LOG(buf, size, fmt, ...) ...

int main(void) {
    char out[64];
    int value = 5;

    LOG(out, sizeof(out), "value=%d", value);
    check_str_msg(out, "[LOG] value=5", "LOG should format with arguments");

    LOG(out, sizeof(out), "ok");
    check_str_msg(out, "[LOG] ok", "LOG should work without extra args");

    return 0;
}
