#include <stdio.h>
#include "clings.h"

/*
 * Stringification turns tokens into double quoted string literals.
 * Rules:
 *   1. Leading/trailing spaces are removed; internal spaces collapse to one.
 *   2. Automatically adds backslashes to " and \ within the argument.
 *   3. Macro arguments used with # are NOT expanded first.
 *   4. To stringify the VALUE of a macro, use a nested wrapper macro.
 *   5. Turns any sequence of tokens into a string, regardless of C validity.
 */

// TODO: Implement STR so that STR(ANSWER) expands to "42".
// Hint: You need another level of indirection so that the preprocessor expands x before stringifying it
// #define STR_HELPER(x) ...
#define STR(x) #x

#define ANSWER 42

int main(void) {
    const char *text = STR(ANSWER);

    check_str_msg(text, "42", "STR should expand macros before stringifying");

    return 0;
}
