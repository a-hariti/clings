#include <stdio.h>
#include "clings.h"

/*
 * Goal: Apply const qualifiers correctly in function parameters.
 *
 * This function should not modify the input array.
 */
int sum(int *nums, size_t len) {
    // TODO: Make the parameter const-correct and remove the mutation.
    nums[0] = 0;
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
