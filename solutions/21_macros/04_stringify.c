#include <stdio.h>
#include "clings.h"

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define ANSWER 42

int main(void) {
    const char *text = STR(ANSWER);

    check_str_msg(text, "42", "STR should expand macros before stringifying");

    return 0;
}
