/*
 * Program  : malloc() - Dynamic Memory Allocation
 * Author   : PAVAN SHETTY H S
 * Topic    : Dynamic Memory Allocation
 *
 * malloc(size) allocates 'size' bytes on the HEAP.
 * Returns void* pointer, or NULL if allocation fails.
 * Memory is NOT initialized (contains garbage).
 * Must be freed using free() after use!
 *
 * Note: Dynamic memory is rarely used on small MCUs (8/16-bit)
 * because of limited RAM and no OS. But important for interviews!
 *
 * Expected Output:
 * Allocated array: 10 20 30 40 50
 * Memory freed successfully.
 */

#include <stdio.h>
#include <stdlib.h>  /* for malloc, free */

int main()
{
    int n = 5;
    int *arr;

    /* Allocate memory for 5 integers */
    arr = (int*) malloc(n * sizeof(int));

    /* ALWAYS check if allocation was successful! */
    if(arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated successfully for %d integers\n", n);

    /* Fill and print array */
    int i;
    for(i = 0; i < n; i++)
        arr[i] = (i + 1) * 10;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* Free the memory when done */
    free(arr);
    arr = NULL;  /* Good practice: set to NULL after free */
    printf("Memory freed.\n");

    /* Dynamic string example */
    char *msg = (char*) malloc(50 * sizeof(char));
    if(msg != NULL)
    {
        sprintf(msg, "Embedded C by PAVAN SHETTY H S");
        printf("Dynamic string: %s\n", msg);
        free(msg);
        msg = NULL;
    }

    return 0;
}
