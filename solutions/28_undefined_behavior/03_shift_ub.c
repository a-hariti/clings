#include <stdio.h>
#include "clings.h"

int safe_shift(int value, int shift) {
    int bit_width = (int)(sizeof(int) * 8);
    if (shift < 0 || shift >= bit_width) {
        return 0;
    }
    return value << shift;
}

int main(void) {
    check_int_msg(safe_shift(1, 3), 8, "1 << 3 should be 8");
    check_int_msg(safe_shift(1, -1), 0, "Negative shifts should be rejected");

    return 0;
}
