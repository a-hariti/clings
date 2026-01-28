#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * In C, a string literal is a sequence of characters in double quotes.
 * You can assign a string literal to a pointer to char.
 * The pointer will then point to the first character of that string literal.
 *
 * Task: Assign the string literal "C-lings" to the 'message' variable.
 */

int main(void) {
    char *message = NULL;

    // TODO: Assign the string literal "C-lings" to the 'message' variable
    message;

    cling_assert(message != NULL, "The message pointer should not be NULL.");
    if (message != NULL) {
        check_str_msg(message, "C-lings", "The message should be 'C-lings'.");
    }

    return 0;
}
