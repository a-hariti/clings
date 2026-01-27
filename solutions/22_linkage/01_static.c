#include <stdio.h>
#include "clings.h"

/*
 * In C, 'static' at the file scope (outside any function) gives a
 * variable or function "internal linkage". This means it's only
 * visible within this file.
 *
 * Linkage must be consistent between declarations and definitions.
 * If you declare a function as 'extern' (the default) and then define
 * it as 'static', you'll get a compiler error!
 *
 * Task: Fix the linkage mismatch for 'get_secret_code' so it is
 * correctly identified as a static function throughout the file.
 */

// TODO: Fix this declaration to match the definition below
static int get_secret_code(void);

int main(void) {
    int code = get_secret_code();

    printf("The secret code is: %d\n", code);

    cling_assert(code == 42, "The secret code should be 42");

    return 0;
}

static int get_secret_code(void) {
    return 42;
}