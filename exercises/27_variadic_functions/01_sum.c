#include <stdarg.h>
#include <stdio.h>
#include "clings.h"

/*
 * Goal: Implement the sum function using variadic arguments.
 * The first argument 'count' tells you how many integers follow.
 *
 * Use va_list, va_start, va_arg, and va_end from <stdarg.h>.
 */
int sum(int count, ...) {
    // ??? args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int main(void) {
    check_int(sum(3, 10, 20, 30), 60);
    check_int(sum(5, 1, 2, 3, 4, 5), 15);
    check_int(sum(0), 0);

    return 0;
}
