#include <stdio.h>
#include "clings.h"

/*
 * Strings in C are represented as arrays of characters followed by a null terminator '\0'.
 * A string literal is simply a sequence of characters enclosed in double quotes.
 *
 * In this exercise, try to print "Hello, C-lings!" using printf.
 * But wait, something is wrong with the string literal!
 */

int main(void) {
    // Fixed: Added double quotes around the string literal
    printf("Hello, C-lings!\n");

    cling_assert(1, "The program should run and print the string.");

    return 0;
}
