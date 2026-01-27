#include <stdio.h>
#include "clings.h"

int main(void) {
    // Variable must be initialized before use!
    int x = 42;

    check_int(x, 42);
    return 0;
}