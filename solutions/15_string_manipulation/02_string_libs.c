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

    /* Copy s1 safely. strncpy is used here, and since s1 is shorter than
     * the buffer, it will be null-terminated. However, it is good practice
     * to ensure the buffer is null-terminated manually if you use strncpy.
     */
    strncpy(buffer, s1, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    /* Concatenate s2 safely.
     * strncat takes the number of characters to copy, and it ALWAYS
     * appends a null terminator.
     */
    strncat(buffer, s2, sizeof(buffer) - strlen(buffer) - 1);

    check_str_msg(buffer, "Learning C is ", "Buffer should contain \"Learning C is \"");
    check_size_msg(strlen(buffer), 14, "Buffer length should be 14");

    return 0;
}
