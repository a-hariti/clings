#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * Goal: Use errno and strerror for error reporting.
 */
int main(void) {
    const char *missing = "c_lings_missing_file_12345.tmp";
    FILE *fp = fopen(missing, "r");

    int err = 0;
    const char *msg = NULL;

    // TODO: If fopen failed, capture errno and convert it to a message with strerror.
    // if (fp == NULL) {
    //     err = errno;
    //     msg = strerror(err);
    // }

    check_bool_msg(fp == NULL, 1, "File open should fail for a missing file");
    check_bool_msg(err != 0, 1, "errno should be set on failure");
    check_bool_msg(msg != NULL, 1, "strerror should return a message");

    if (fp) {
        fclose(fp);
    }
    return 0;
}
