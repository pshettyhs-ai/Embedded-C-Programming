/*
 * Program  : Pointers and Arrays
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * Array name is basically a constant pointer to first element.
 * arr[i]  is same as  *(arr + i)
 * &arr[i] is same as  (arr + i)
 *
 * Expected Output:
 * arr[2] = 30
 * *(arr+2) = 30   (same thing!)
 */

#include <stdio.h>

/* Function using pointer instead of array syntax */
int sum_array(int *arr, int n)
{
    int sum = 0, i;
    for(i = 0; i < n; i++)
        sum += *(arr + i);  /* pointer notation */
    return sum;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, i;

    printf("--- Array vs Pointer Notation ---\n");
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d  |  *(arr+%d) = %d\n",
                i, arr[i], i, *(arr+i));
    }

    printf("\nSum using pointer function: %d\n", sum_array(arr, n));

    /* Pointer to traverse array */
    printf("\n--- Traversal with pointer ---\n");
    int *ptr;
    for(ptr = arr; ptr < arr + n; ptr++)
        printf("%d ", *ptr);
    printf("\n");

    /* 2D array and pointer */
    printf("\n--- 2D Array with Pointer ---\n");
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    int *mp = &matrix[0][0];  /* pointer to first element */
    int row, col;
    for(row = 0; row < 2; row++)
    {
        for(col = 0; col < 3; col++)
            printf("%d ", *(mp + row*3 + col));
        printf("\n");
    }

    return 0;
}
