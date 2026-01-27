#include <stdio.h>
#include "clings.h"

/*
 * C programs can accept command line arguments.
 * To access them, main must be declared with:
 * int main(int argc, char *argv[])
 *
 * - argc: the number of arguments (including the program name)
 * - argv: an array of strings (char*)
 *
 * Fix the signature of main to accept these arguments.
 */

int main(int argc, char *argv[]) {
    // argc should be at least 1 (the program name itself)
    cling_assert(argc >= 1, "argc should be at least 1");

    // argv[0] is the program name
    cling_assert(argv[0] != NULL, "argv[0] should not be NULL");

    // The last element of argv is always NULL
    cling_assert(argv[argc] == NULL, "argv[argc] should be NULL");

    printf("Executing: %s\n", argv[0]);

    return 0;
}
