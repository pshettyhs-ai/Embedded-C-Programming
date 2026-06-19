/*
 * Program  : calloc() - Contiguous Allocation
 * Author   : PAVAN SHETTY H S
 * Topic    : Dynamic Memory Allocation
 *
 * calloc(n, size) allocates memory for n elements of 'size' bytes each.
 * DIFFERENCE from malloc: calloc INITIALIZES all bytes to ZERO!
 *
 * Expected Output:
 * calloc array (zero-initialized): 0 0 0 0 0
 * malloc array (garbage values):   (unpredictable)
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;

    /* calloc - memory is ZERO initialized */
    int *arr_calloc = (int*) calloc(n, sizeof(int));
    if(arr_calloc == NULL) { printf("calloc failed\n"); return 1; }

    printf("calloc array (zero-initialized): ");
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr_calloc[i]);
    printf("\n");

    /* malloc - memory has garbage values */
    int *arr_malloc = (int*) malloc(n * sizeof(int));
    if(arr_malloc == NULL) { printf("malloc failed\n"); free(arr_calloc); return 1; }

    printf("malloc array (may have garbage): ");
    for(i = 0; i < n; i++) printf("%d ", arr_malloc[i]);
    printf("\n");

    free(arr_calloc); arr_calloc = NULL;
    free(arr_malloc); arr_malloc = NULL;

    /* Interview Note:
     * malloc(n * size)  = allocate, NO initialization
     * calloc(n, size)   = allocate + ZERO initialize
     * realloc(ptr, size)= resize existing allocation
     * free(ptr)         = release memory
     */
    printf("\ncalloc vs malloc:\n");
    printf("calloc = allocate + zero-fill (safer)\n");
    printf("malloc = allocate only (faster but garbage values)\n");

    return 0;
}
