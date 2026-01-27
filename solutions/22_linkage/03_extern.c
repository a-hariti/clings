#include <stdio.h>
#include "clings.h"

/*
 * The 'extern' keyword is used to declare a variable that is defined
 * somewhere else (either later in the same file or in a different
 * translation unit).
 *
 * It tells the compiler about the variable's type and name without
 * allocating memory for it. This allows multiple parts of a program
 * to share the same global variable.
 *
 * Task: The variable 'level_difficulty' is defined at the bottom of
 * this file. Declare it at the top using 'extern' so that main()
 * can access it.
 */

// Declare level_difficulty as an external integer here
extern int level_difficulty;

int main(void) {
    // This will cause a compiler error if 'level_difficulty' is not declared
    printf("Current difficulty: %d\n", level_difficulty);

    cling_assert(level_difficulty == 10, "Should be able to read the defined value");

    level_difficulty = 20;
    check_int(level_difficulty, 20);

    return 0;
}

// Definition of the variable
int level_difficulty = 10;
