#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * Goal: Read a line safely with fgets.
 *
 * We'll use a temporary file as our input source to keep the exercise
 * testable without interactive input.
 */
int main(void) {
    char buffer[32];
    char *result = NULL;

    FILE *fp = tmpfile();
    cling_assert(fp != NULL, "tmpfile should succeed");

    fputs("C-lings\n", fp);
    rewind(fp);

    // TODO: Read one line into buffer using fgets.
    // result = fgets(<buffer>, <buffer size>, <stream>);

    cling_assert(result != NULL, "fgets should read a line");

    // TODO: Remove the trailing newline if present.
    // Hint:
    //  Locate the '\n' character with strcspn(<str>, "\n")
    //  Set buffer[<index>] to null character:

    check_str_msg(buffer, "C-lings", "Buffer should contain the input without newline");

    fclose(fp);
    return 0;
}
