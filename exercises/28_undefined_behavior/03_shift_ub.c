#include <stdio.h>
#include "clings.h"

/*
 * Goal: Avoid undefined behavior when shifting.
 *
 * Shifting by a negative value or by an amount >= the bit width is undefined.
 */
int safe_shift(int value, int shift) {
    // TODO: Guard against invalid shifts. Return 0 for invalid shifts.
    return value << shift;
}

int main(void) {
    check_int_msg(safe_shift(1, 3), 8, "1 << 3 should be 8");
    check_int_msg(safe_shift(1, -1), 0, "Negative shifts should be rejected");

    return 0;
}
