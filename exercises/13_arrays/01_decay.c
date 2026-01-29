#include <stdio.h>
#include "clings.h"

/*
 * Fix the array size calculation (array decay).
 * In C, when an array is passed to a function, it decays into a pointer.
 * This means sizeof(arr) inside the function is the size of the pointer,
 * not the entire array.
 *
 * Task: Modify the sum_array function and its call to correctly
 * process all elements of the array.
 */

int sum_array(int arr[]) {
    int sum = 0;
    /* BUG: sizeof(arr) here is sizeof(int*), not the size of the array! */
    size_t len = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int expected_sum = 10 + 20 + 30 + 40 + 50;

    /* This will fail because sum_array won't iterate over all elements. */
    check_int(sum_array(numbers), expected_sum);

    return 0;
}