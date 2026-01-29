#include <stdio.h>
#include "clings.h"

int main(void) {
    int values[4] = {10, 20, 30, 40};

    int *ptr = values;
    const int *first = &values[0];
    const int *second = values + 1;
    size_t array_bytes = sizeof(values);
    size_t ptr_bytes = sizeof(ptr);

    check_ptr_msg(values, first, "arr and &arr[0] point to the same address");
    check_ptr_msg(values + 1, second, "arr + 1 points to the next element");
    check_size_msg(array_bytes, sizeof(int) * 4, "Array size should include all elements");
    check_size_msg(ptr_bytes, sizeof(int *), "Pointer size should not match array size");
    check_ptr_msg(ptr, values, "Pointer should be set to the array base");

    return 0;
}
