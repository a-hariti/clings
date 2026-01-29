#include <stddef.h>
#include "clings.h"

/*
 * Goal: Use offsetof to compute field offsets in a struct.
 */
struct Packet {
    char tag;
    int id;
    double value;
};

int main(void) {
    size_t off_id = 0;
    size_t off_value = 0;

    // TODO: Use offsetof to compute field offsets.
    // off_id = offsetof(<struct>, <field>);
    // off_value = offsetof(<struct>, <field>);

    check_size_msg(off_id, offsetof(struct Packet, id), "id offset should match offsetof");
    check_size_msg(off_value, offsetof(struct Packet, value), "value offset should match offsetof");

    return 0;
}
