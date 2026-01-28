#include <stdio.h>
#include "clings.h"

int main(void) {
    int n = 42;
    int *p = &n;

    check_ptr_msg(p, &n, "p should point to n");
    check_int(*p, 42);

    return 0;
}
