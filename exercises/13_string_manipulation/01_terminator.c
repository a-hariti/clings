#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * Strings in C are character arrays terminated by a null byte '\0'.
 * This terminator is essential for functions like strlen(), printf(), etc.
 *
 * When you initialize a string with "Literal", C automatically adds the '\0'.
 * However, the array must be large enough to hold it!
 *
 * Task: Fix the array size to accommodate the null terminator.
 */

int main(void) {
    /* TODO: Fix the array size to include space for the null terminator '\0' */
    char my_string[5] = "Hello";

    check_size_msg(strlen(my_string), 5, "String length should be 5");

    return 0;
}
