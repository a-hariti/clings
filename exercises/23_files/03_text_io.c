#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * Goal: Use text file I/O idiomatically with fgets.
 */
int main(void) {
    const char *filename = "lines.txt";

    FILE *out = fopen(filename, "w");
    cling_assert(out != NULL, "fopen should succeed for writing");
    fprintf(out, "Alice\n");
    fprintf(out, "Bob\n");
    fclose(out);

    FILE *in = fopen(filename, "r");
    cling_assert(in != NULL, "fopen should succeed for reading");

    char line[32];
    char first[32] = {0};
    int count = 0;

    // TODO: Read lines using fgets and count them.
    // Hint: store the first line so we can check it later.
    // while (fgets(<buffer>, <size>, <stream>)) { ... }

    check_int_msg(count, 2, "Should read two lines");
    check_str_msg(first, "Alice", "First line should be Alice");

    fclose(in);
    remove(filename);

    return 0;
}
