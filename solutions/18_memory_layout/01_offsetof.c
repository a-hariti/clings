#include <stddef.h>
#include "clings.h"

struct Packet {
    char tag;
    int id;
    double value;
};

int main(void) {
    size_t off_id = offsetof(struct Packet, id);
    size_t off_value = offsetof(struct Packet, value);

    check_size_msg(off_id, offsetof(struct Packet, id), "id offset should match offsetof");
    check_size_msg(off_value, offsetof(struct Packet, value), "value offset should match offsetof");

    return 0;
}
