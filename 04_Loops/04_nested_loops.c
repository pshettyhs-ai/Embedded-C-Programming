/*
 * Program  : Nested Loops in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * A loop inside another loop is called nested loop.
 * Used for: 2D arrays, patterns, matrix operations, scanning rows & columns.
 *
 * Expected Output:
 * Multiplication Table:
 *    1  2  3  4  5
 *    2  4  6  8 10
 *    ...
 */

#include <stdio.h>

int main()
{
    int i, j;

    /* 5x5 Multiplication Table */
    printf("--- Multiplication Table ---\n");
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            printf("%4d", i * j);  /* %4d = 4 character wide */
        }
        printf("\n");
    }

    /* Star pattern */
    printf("\n--- Right Triangle Pattern ---\n");
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    /* Embedded: Initialize a 2D sensor grid (3x3) */
    printf("\n--- 2D Sensor Grid (row x col) ---\n");
    int sensor_grid[3][3];
    int row, col;

    /* Initialize grid with some values */
    for(row = 0; row < 3; row++)
        for(col = 0; col < 3; col++)
            sensor_grid[row][col] = (row * 3) + col + 1;  /* values 1-9 */

    /* Print the grid */
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
            printf("[%2d] ", sensor_grid[row][col]);
        printf("\n");
    }

    return 0;
}
