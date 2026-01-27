#include <stdio.h>
#include "clings.h"

/*
 * In C, 'static' used inside a function gives a variable "static storage
 * duration". This means the variable is initialized once and retains
 * its value between function calls.
 *
 * This is useful for creating counters, caching results, or managing
 * state that should be private to a function but persistent.
 *
 * Task: Modify the 'counter' function so that 'count' is persistent.
 * Each time 'counter()' is called, it should increment and return
 * the new value.
 *
 * Further reading: Beej's Guide to C Programming, Section 11.2 (static)
 * Man page: man 3 (not applicable for keywords)
 */

int counter(void) {
    // FIXED: Added 'static' to make the variable persistent
    static int count = 0;
    count++;
    return count;
}

int main(void) {
    printf("First call: %d\n", counter());
    printf("Second call: %d\n", counter());
    printf("Third call: %d\n", counter());

    check_int(counter(), 4);
    check_int(counter(), 5);

    return 0;
}