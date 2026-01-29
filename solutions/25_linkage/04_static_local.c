#include <stdio.h>
#include "clings.h"

int next_id(void) {
    static int id = 0;
    id++;
    return id;
}

int main(void) {
    check_int_msg(next_id(), 1, "First id should be 1");
    check_int_msg(next_id(), 2, "Second id should be 2");
    check_int_msg(next_id(), 3, "Third id should be 3");

    return 0;
}
