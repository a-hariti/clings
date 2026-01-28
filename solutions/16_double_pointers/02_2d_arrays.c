#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

int **allocate_matrix(size_t rows, size_t cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL)
        return NULL;

    for (size_t i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));

        if (matrix[i] == NULL) {
            // Clean up already allocated rows on failure up to i-1
            for (size_t j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(int **matrix, size_t rows) {
    // TODO: You need to free each row before freeing the matrix pointer itself.
    // If you only free(matrix), you'll have a memory leak!
    for (size_t i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
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

    check_int_msg(ACTIVE_ALLOCATIONS, NUM_ALLOCATIONS, "Matrix is fully allocated");

    // This works
    fill_matrix(matrix, rows, cols, 0);

    // Clean up
    free_matrix(matrix, rows);

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
