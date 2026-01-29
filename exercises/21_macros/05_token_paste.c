#include <stdio.h>
#include "clings.h"

/*
 * Token pasting lets you build identifiers from pieces.
 * Rules:
 *   1. Resulting token must be a valid C identifier, keyword, or literal.
 *   2. Macro arguments used with ## are NOT expanded first a literal copy paste.
 *   3. To paste the VALUE of a macro, use a nested wrapper macro.
 *   4  Cannot be the first or last token in a macro definition.
 *   5. Spaces surrounding ## are ignored during the merge.
 */

// TODO: Implement JOIN so JOIN(value_, 1) becomes value_1.
// #define JOIN(a, b) ...

int main(void) {
    int value_1 = 7;

    int result = JOIN(value_, 1);

    check_int_msg(result, 7, "JOIN should build the identifier value_1");

    return 0;
}
