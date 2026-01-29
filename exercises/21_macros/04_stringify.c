#include <stdio.h>
#include "clings.h"

/*
 * Stringification turns tokens into string literals.
 */

// TODO: Implement STR so that STR(ANSWER) expands to "42".
// #define STR_HELPER(x) ...
// #define STR(x) ...

#define ANSWER 42

int main(void) {
    const char *text = STR(ANSWER);

    check_str_msg(text, "42", "STR should expand macros before stringifying");

    return 0;
}
