#include <stdio.h>
#include "clings.h"

/*
 * The `const` keyword is used to declare variables whose value cannot be changed.
 * This is useful for defining constants that should remain the same throughout
 * the program's execution, preventing accidental modifications.
 *
 * This code tries to modify a `const` variable, which will cause a compiler error.
 * Fix the code so that it compiles and passes the assertion.
 */

int main(void) {
    const int MAX_USERS = 100;

    // TODO: Fix the error below without changing the declaration of MAX_USERS
    MAX_USERS = 200;

    check_int(MAX_USERS, 100);

    return 0;
}