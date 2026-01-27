// C-style comments /* ... */ cannot be nested.
// The compiler gets confused when it sees the first '*/' and thinks
// the comment has ended.
// Fix the code below so it compiles.
// clang-format off

#include <stdio.h>

int main(void) {
    /* This is an outer comment
       /* This nested comment will break things! */
       The compiler thinks the comment ended above.
    */
        printf("Comments fixed!\n");
    return 0;
}
