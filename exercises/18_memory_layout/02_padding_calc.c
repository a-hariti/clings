#include <stddef.h>
#include "clings.h"

/*
 * Goal: Calculate padding using offsetof and sizeof.
 */
struct Weird {
    char a;
    int b;
    char c;
};

int main(void) {
    size_t padding_between = 0;
    size_t tail_padding = 0;

    // TODO: Compute padding before b and after c.
    // padding_between = offsetof(struct Weird, b) - offsetof(struct Weird, a) - sizeof(char);
    // tail_padding = sizeof(struct Weird) - (offsetof(struct Weird, c) + sizeof(char));

    check_size_msg(padding_between, offsetof(struct Weird, b) - offsetof(struct Weird, a) - sizeof(char),
                   "padding before b should match computed value");
    check_size_msg(tail_padding, sizeof(struct Weird) - (offsetof(struct Weird, c) + sizeof(char)),
                   "tail padding should match computed value");

    return 0;
}
