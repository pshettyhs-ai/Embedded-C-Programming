/*
 * Program  : 2D Array in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * 2D array = array of arrays = matrix
 * Used in: image processing, LED matrix, keypad scanning
 *
 * Expected Output:
 * Matrix:
 *  1  2  3
 *  4  5  6
 *  7  8  9
 */

#include <stdio.h>

int main()
{
    int i, j;

    /* 2D array (3 rows, 3 columns) */
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    /* Print matrix */
    printf("Matrix:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }

    /* Sum of main diagonal */
    int diag_sum = 0;
    for(i = 0; i < 3; i++)
        diag_sum += matrix[i][i];
    printf("Diagonal sum: %d\n", diag_sum);

    /* Matrix Transpose */
    printf("\nTranspose:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%3d", matrix[j][i]);  /* swap i and j */
        printf("\n");
    }

    /* Embedded: 4x4 Keypad mapping */
    printf("\n--- 4x4 Keypad Layout ---\n");
    char keypad[4][4] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
    };

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
            printf("[%c] ", keypad[i][j]);
        printf("\n");
    }

    return 0;
}
