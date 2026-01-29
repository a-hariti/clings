#include <stdio.h>
#include "clings.h"

int sum(const int *nums, size_t len) {
    int total = 0;
    for (size_t i = 0; i < len; i++) {
        total += nums[i];
    }
    return total;
}

int main(void) {
    const int nums[] = {1, 2, 3};
    int total = sum(nums, 3);

    check_int_msg(total, 6, "Sum should be 6 without modifying input");

    return 0;
}
