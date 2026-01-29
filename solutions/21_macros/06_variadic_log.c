#include <stdio.h>
#include "clings.h"

#define LOG(buf, size, fmt, ...) snprintf((buf), (size), "[LOG] " fmt __VA_OPT__(, ) __VA_ARGS__)

int main(void) {
    char out[64];
    int value = 5;

    LOG(out, sizeof(out), "value=%d", value);
    check_str_msg(out, "[LOG] value=5", "LOG should format with arguments");

    LOG(out, sizeof(out), "ok");
    check_str_msg(out, "[LOG] ok", "LOG should work without extra args");

    return 0;
}
