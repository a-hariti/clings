#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * In C, a dynamic 2D array can be represented as a pointer to an array of pointers.
 * Each pointer in the first array points to another array (a row).
 *
 * This requires two steps:
 * 1. Allocate an array of pointers: `int **matrix = malloc(rows * sizeof(int *));`
 * 2. For each row, allocate an array of integers: `matrix[i] = malloc(cols * sizeof(int));`
 *
 * Don't forget that you must free the memory in reverse order!
 */

int **allocate_matrix(size_t rows, size_t cols) {
    // ignore this line
    (void)cols;

    // TODO: Fix the allocation. It's currently using the wrong size for an array of pointers!
    // Hint: we are allocating an array of row pointers (int *).
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL)
        return NULL;

    for (size_t i = 0; i < rows; i++) {
        // TODO: Each matrix[i] needs to be allocated to hold 'cols' integers.
        // matrix[i] = malloc(cols * sizeof(int));
        matrix[i] = NULL; // Initialized to NULL
    }
    return matrix;
}

// silence unused parameter from clang-tidy
void free_matrix(int **matrix) {
    // TODO: You need to free each row before freeing the matrix pointer itself.
    // If you only free(matrix), you'll have a memory leak!
    free((void *)matrix);
}

// uses the matrix
void fill_matrix(int **matrix, size_t rows, size_t cols, int value);

int main(void) {
    size_t rows = 3;
    size_t cols = 4;
    // one allocation for the matrix pointer itself and one for each row
    int NUM_ALLOCATIONS = 1 + (int)rows;

    int **matrix = allocate_matrix(rows, cols);
    cling_assert(matrix != NULL, "allocate_matrix should return a non NULL pointer ");

    check_int_msg(ACTIVE_ALLOCATIONS, NUM_ALLOCATIONS, "Matrix is fully allocated (cols x rows)");

    // Fill the matrix with zeros as a sanity check that we have access to the matrix memory.
    // uncomment this when you properly alocate the matrix
    // fill_matrix(matrix, rows, cols, 0);

    // Clean up
    free_matrix(matrix);

    check_int_msg(ACTIVE_ALLOCATIONS, 0, "All allocations should be freed");

    return 0;
}

void fill_matrix(int **matrix, size_t rows, size_t cols, int value) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}
