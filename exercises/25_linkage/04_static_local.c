#include <stdio.h>
#include "clings.h"

/*
 * Goal: Use a static local variable to preserve state between calls.
 */
int next_id(void) {
    int id = 0;
    // TODO: Make id persist and increment across calls.
    return id;
}

int main(void) {
    check_int_msg(next_id(), 1, "First id should be 1");
    check_int_msg(next_id(), 2, "Second id should be 2");
    check_int_msg(next_id(), 3, "Third id should be 3");

    return 0;
}
