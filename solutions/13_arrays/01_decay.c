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

int sum_array(int arr[], size_t len) {
    int sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t len = sizeof(numbers) / sizeof(numbers[0]);
    int expected_sum = 10 + 20 + 30 + 40 + 50;

    /* Correctly pass the length to the function */
    check_int(sum_array(numbers, len), expected_sum);

    return 0;
}