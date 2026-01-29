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

    /* TODO: Check if fp is NULL and set error_detected to 1 if it is. */
    /* If it's NOT NULL, make sure to fclose(fp). */

    // In a real program, you'd handle the error here.
    // For now, we'll just record that we detected it.

    // BUG: Missing check.
    // If you don't check for NULL, you might pass a NULL pointer to fclose()
    // which is undefined behavior.
    fclose(fp);

    check_int(error_detected, 1);

    return 0;
}