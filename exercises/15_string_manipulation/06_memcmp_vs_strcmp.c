#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * strcmp stops at the first '\0'.
 * memcmp compares a fixed number of bytes.
 */

int main(void) {
    unsigned char a[4] = {'A', '\0', 'B', 0};
    unsigned char b[4] = {'A', '\0', 'C', 0};

    // TODO: Compare all bytes and detect the difference.
    bool equal = false;

    check_bool_msg(equal, false, "Buffers should not be equal");

    return 0;
}
