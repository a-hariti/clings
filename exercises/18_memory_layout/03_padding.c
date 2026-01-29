#include <stdio.h>
#include "clings.h"

/*
 * Goal: Optimize struct layout.
 *
 * Compilers add padding between struct members to satisfy alignment
 * requirements. By reordering members, you can reduce the amount of
 * padding and the overall size of the struct.
 *
 * Generally, ordering members from largest to smallest type is a good
 * strategy to minimize padding.
 *
 * Example layout (8-byte alignment):
 *
 *   struct Bloated {
 *     char a;   // 1 byte
 *     long b;   // 8 bytes
 *     char c;   // 1 byte
 *   };
 *
 *   Bytes (a=1, b=8, c=1, p=padding):
 *     [a][p][p][p][p][p][p][p][b][b][b][b][b][b][b][b][c][p][p][p][p][p][p][p]
 *      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
 *
 *   Offsets:
 *     a @ 0
 *     padding 7 bytes
 *     b @ 8
 *     c @ 16
 *     padding 7 bytes
 *
 *   Total: 24 bytes
 *
 * Reorder to pack:
 *
 *   struct Packed {
 *     long b;   // @ 0 (8)
 *     char a;   // @ 8 (1)
 *     char c;   // @ 9 (1)
 *   };
 *   padding 6 bytes
 *
 *   Bytes:
 *     [b][b][b][b][b][b][b][b][a][c][p][p][p][p][p][p]
 *      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
 *
 *   Total: 16 bytes
 */

struct OptimizedMe {
    char a;
    long b;
    char c;
};

int main(void) {
    // On most 64-bit systems, the current layout takes 24 bytes.
    // Your goal is to reorder the members to reduce the size to 16 bytes.

    printf("Size of struct OptimizedMe: %zu\n", sizeof(struct OptimizedMe));

    // TODO: Reorder the members in 'struct OptimizedMe' so that the size is 16 bytes.
    check_size_msg(sizeof(struct OptimizedMe), 16, "Struct should be 16 bytes after reordering");

    return 0;
}
