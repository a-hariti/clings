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

enum Status { STATUS_OK, STATUS_ERROR, STATUS_PENDING };

int main(void) {
    enum Status s = STATUS_PENDING;

    check_enum_msg(s, 2, "STATUS_PENDING should map to 2");
    check_enum_msg(s, STATUS_PENDING, "Status should be PENDING");

    return 0;
}
