#include <stdio.h>
#include "clings.h"

/*
 * Exercise: 02_include_guards.c
 *
 * Header files often contain definitions like structs or enums.
 * If a header is included twice in the same C file, it can cause
 * redefinition errors. To prevent this, we use "include guards".
 *
 * Your task: Add include guards to "02_include_guards.h" to allow
 * this file to compile successfully with multiple inclusions.
 *
 * Note: You don't need to change this .c file, only the .h file.
 */

#include "02_include_guards.h"

int main(void) {
    struct Point p = {10, 20};

    check_int(p.x, 10);
    check_int(p.y, 20);

    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
    printf("Successfully handled multiple inclusions!\n");

    return 0;
}
