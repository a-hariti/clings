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

    check_int((int)s, 2);
    cling_assert(s == STATUS_PENDING, "Status should be PENDING");

    return 0;
}
