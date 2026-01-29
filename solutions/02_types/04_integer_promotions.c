#include <stdio.h>
#include "clings.h"

int main(void) {
    unsigned char a = 250;
    unsigned char b = 10;

    int sum = a + b;

    check_int_msg(sum, 260, "Sum should keep the full value");

    return 0;
}
