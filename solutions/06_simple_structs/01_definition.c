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

    check_int_msg(p.age, 30, "Age should be 30");
    check_str_msg(p.name, "Alice", "Name should be Alice");

    return 0;
}
