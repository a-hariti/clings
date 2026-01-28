#include <stdio.h>
#include "clings.h"

/*
 * Goal: Define and use an enumeration.
 *
 * Requirements:
 * 1. Define an 'enum Status' with values:
 *    - STATUS_OK (should be 0)
 *    - STATUS_ERROR (should be 1)
 *    - STATUS_PENDING (should be 2)
 * 2. Create a variable of type 'enum Status' and assign it a value.
 */

// TODO: Define the enum Status here

int main(void) {
    // TODO: Declare a variable 's' of type 'enum Status' and set it to STATUS_PENDING
    enum Status s;

    check_enum_msg(s, 2, "STATUS_PENDING should map to 2");
    check_eq_msg(s, STATUS_PENDING, "Status should be PENDING");

    return 0;
}
