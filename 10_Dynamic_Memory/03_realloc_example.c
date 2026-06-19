/*
 * Program  : realloc() - Resize Allocated Memory
 * Author   : PAVAN SHETTY H S
 * Topic    : Dynamic Memory Allocation
 *
 * realloc(ptr, new_size) resizes previously allocated memory.
 * Old data is preserved. May move to a new location.
 *
 * Expected Output:
 * Original (5 elements): 10 20 30 40 50
 * Resized  (8 elements): 10 20 30 40 50 60 70 80
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5, i;

    /* Initial allocation */
    int *arr = (int*) malloc(n * sizeof(int));
    if(!arr) { printf("malloc failed\n"); return 1; }

    for(i = 0; i < n; i++) arr[i] = (i+1) * 10;

    printf("Original (%d elements): ", n);
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    /* Resize to 8 elements */
    int new_n = 8;
    int *temp = (int*) realloc(arr, new_n * sizeof(int));

    /* IMPORTANT: use a temp pointer in case realloc fails */
    if(!temp)
    {
        printf("realloc failed! Original array still valid.\n");
        free(arr);
        return 1;
    }
    arr = temp;  /* safe to reassign now */

    /* Fill new elements */
    for(i = n; i < new_n; i++) arr[i] = (i+1) * 10;

    printf("Resized  (%d elements): ", new_n);
    for(i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    printf("Memory freed.\n");

    return 0;
}
