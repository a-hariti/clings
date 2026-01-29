#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    char word[] = "hello";

    size_t len = strlen(word);

    check_size_msg(len, 5, "Length should be 5 characters");

    return 0;
}
