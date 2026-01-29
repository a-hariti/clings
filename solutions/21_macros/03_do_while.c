#include <stdio.h>
#include "clings.h"

#define ADD_IF_POSITIVE(x, y)                                                                                          \
    do {                                                                                                               \
        if ((y) > 0)                                                                                                   \
            (x) += (y);                                                                                                \
    } while (0)

int main(void) {
    int x = 0;
    int y = 1;
    int flag = 0;

    if (flag)
        ADD_IF_POSITIVE(x, y);
    else
        x = 5;

    check_int_msg(x, 5, "x should be set by the else branch");

    return 0;
}
