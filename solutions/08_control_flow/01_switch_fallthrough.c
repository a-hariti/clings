#include <stdio.h>
#include "clings.h"

/*
 * Fix the accidental switch fallthrough.
 * In C, if you don't use 'break' in a switch case, execution
 * "falls through" to the next case!
 */

int get_days_in_month(int month) {
    int days = 0;
    switch (month) {
    case 2:
        days = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    default:
        days = 31;
        break;
    }
    return days;
}

int main(void) {
    /* February should have 28 days (ignoring leap years) */
    check_int(get_days_in_month(2), 28);
    check_int(get_days_in_month(4), 30);
    check_int(get_days_in_month(1), 31);

    printf("All tests passed!\n");
    return 0;
}