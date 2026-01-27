#include <stdio.h>
#include "clings.h"

/*
 * Goal: Define and initialize a simple struct.
 *
 * Requirements:
 * 1. Define a 'struct Person' with:
 *    - const char *name
 *    - int age
 * 2. Initialize it in main with name "Alice" and age 30.
 */

// TODO: Define the struct Person here

int main(void) {
    // TODO: Initialize a 'struct Person' named 'p' with "Alice" and 30
    struct Person p;

    check_int(p.age, 30);
    // Since we don't have a check_string, we'll use a simple comparison
    cling_assert(p.name != NULL && p.name[0] == 'A', "Name should be Alice");

    return 0;
}
