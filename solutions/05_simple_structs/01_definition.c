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

struct Person {
    const char *name;
    int age;
};

int main(void) {
    struct Person p = {"Alice", 30};

    check_int(p.age, 30);
    cling_assert(p.name != NULL && strcmp(p.name, "Alice") == 0, "Name should be Alice");

    return 0;
}
