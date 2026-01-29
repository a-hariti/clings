#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    char buffer[32];
    char *result = NULL;

    FILE *fp = tmpfile();
    cling_assert(fp != NULL, "tmpfile should succeed");

    fputs("C-lings\n", fp);
    rewind(fp);

    result = fgets(buffer, sizeof(buffer), fp); // NOLINT(clang-analyzer-unix.Errno)
    cling_assert(result != NULL, "fgets should read a line");

    buffer[strcspn(buffer, "\n")] = '\0';

    check_str_msg(buffer, "C-lings", "Buffer should contain the input without newline");

    fclose(fp);
    return 0;
}
