#include <stdio.h>
#include "clings.h"

int main(void) {
    int s = -1;
    unsigned int u = 1;

    int is_less = (s < (int)u);

    check_int_msg(is_less, 1, "-1 should be less than 1 with a correct comparison");

    return 0;
}
