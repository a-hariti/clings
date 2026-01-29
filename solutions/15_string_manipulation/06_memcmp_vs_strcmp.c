#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    unsigned char a[4] = {'A', '\0', 'B', 0};
    unsigned char b[4] = {'A', '\0', 'C', 0};

    bool equal = memcmp(a, b, sizeof(a)) == 0;

    check_bool_msg(equal, false, "Buffers should not be equal");

    return 0;
}
