#include <stdio.h>
#include "clings.h"

/**
 * When opening a file with fopen(), it's crucial to check for errors.
 * If fopen() cannot open the file, it returns NULL.
 *
 * Goal: Check if the file was opened successfully.
 * If it failed, set 'error_detected' to 1.
 */

int main(void) {
    // This file does not exist.
    FILE *fp = fopen("non_existent_file_12345.txt", "r");
    int error_detected = 0;

    /* Check if fp is NULL and set error_detected to 1 if it is. */
    if (fp == NULL) {
        error_detected = 1;
    } else {
        /* If it's NOT NULL, make sure to fclose(fp). */
        fclose(fp);
    }

    check_int(error_detected, 1);

    return 0;
}