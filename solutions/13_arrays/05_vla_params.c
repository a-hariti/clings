#include <stdio.h>
#include "clings.h"

int sum_row(int rows, int cols, int matrix[rows][cols], int row) {
    int total = 0;

    for (int c = 0; c < cols; c++) {
        total += matrix[row][c];
    }

    return total;
}

int main(void) {
    int rows = 2;
    int cols = 3;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };

    int result = sum_row(rows, cols, matrix, 1);

    check_int_msg(result, 15, "Row sum should be 15");

    return 0;
}
