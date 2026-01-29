#include <stddef.h>
#include "clings.h"

int get_at(const int *arr, size_t len, size_t idx, int *out) {
    if (idx >= len) {
        return -1;
    }
    *out = arr[idx];
    return 0;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40};
    int value = 0;

    int ok = get_at(numbers, 4, 2, &value);
    check_int_msg(ok, 0, "Index 2 should be in bounds");
    check_int_msg(value, 30, "Value at index 2 should be 30");

    ok = get_at(numbers, 4, 4, &value);
    check_int_msg(ok, -1, "Index 4 should be out of bounds");

    return 0;
}
