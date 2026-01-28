#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * The string functions in <string.h> often have "n" variants:
 * strncpy, strncat, etc. These help prevent buffer overflows by
 * limiting the number of bytes written.
 *
 * Task:
 * 1. Copy s1 into 'buffer'.
 * 2. Concatenate s2 to it.
 * 3. Ensure 'buffer' (size 15) does not overflow.
 * 4. The final string should be "Learning C is " (14 characters).
 */

int main(void) {
    char buffer[15];
    const char *s1 = "Learning ";
    const char *s2 = "C is fun!";

    /* TODO: Fix this code to use safe string functions and prevent overflow.
     * Use strncpy and strncat appropriately.
     */
    strcpy(buffer, s1);
    strcat(buffer, s2); /* This overflows buffer! */

    check_str_msg(buffer, "Learning C is ", "Buffer should contain \"Learning C is \"");
    check_size_msg(strlen(buffer), 14, "Buffer length should be 14");

    return 0;
}
