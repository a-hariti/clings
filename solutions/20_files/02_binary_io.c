#include <stdio.h>
#include <string.h>
#include "clings.h"

/**
 * Binary I/O allows you to write and read raw memory to/from a file.
 * This is often used for structs or arrays.
 *
 * fwrite(ptr, size, count, stream);
 * fread(ptr, size, count, stream);
 *
 * Goal: Write a struct to a temporary file and then read it back.
 */

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

int main(void) {
    const char *filename = "student.bin";
    Student s1 = {1, "Alice", 95.5f};
    Student s2 = {0};

    // 1. Write s1 to the file
    FILE *out = fopen(filename, "wb");
    if (out == NULL) {
        perror("Failed to open file for writing");
        return 1;
    }

    size_t n_items_written = fwrite(&s1, sizeof(Student), 1, out);

    check_size_msg(n_items_written, 1, "fwrite should write one student to file");

    fclose(out);

    // 2. Read it back into s2
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        perror("Failed to open file for reading");
        return 1;
    }

    size_t n_items_read = fread(&s2, sizeof(Student), 1, in);

    check_size_msg(n_items_read, 1, "fread should read one student from file");

    fclose(in);

    // Verify
    check_int_msg(s2.id, 1, "s2 ID should be 1");
    check_str_msg(s2.name, "Alice", "Name should be Alice");
    check_float_msg(s2.score, 95.5f, "Score should be 95.5");

    // Clean up
    remove(filename);

    return 0;
}
