#include <stdio.h>
#include <string.h>
#include "clings.h"

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

    while (fgets(line, sizeof(line), in) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // NOLINT(clang-analyzer-security.ArrayBound)
        if (count == 0) {
            strncpy(first, line, sizeof(first) - 1);
        }
        count++;
    }

    check_int_msg(count, 2, "Should read two lines");
    check_str_msg(first, "Alice", "First line should be Alice");

    fclose(in);
    remove(filename);

    return 0;
}
