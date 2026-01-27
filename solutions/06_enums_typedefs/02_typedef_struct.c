#include <stdio.h>
#include "clings.h"

/*
 * Goal: Use typedef to simplify struct usage.
 *
 * Requirements:
 * 1. Define a struct for a 'Student' with 'id' (int) and 'grade' (float).
 * 2. Use 'typedef' so that you can use 'Student' as a type without the 'struct' keyword.
 * 3. Initialize a Student named 's' with id 1 and grade 3.5.
 */

typedef struct {
    int id;
    float grade;
} Student;

int main(void) {
    Student s = {1, 3.5f};

    check_int(s.id, 1);
    check_float(s.grade, 3.5f);

    return 0;
}
