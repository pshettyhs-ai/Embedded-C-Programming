/*
 * Program  : Dynamic Array (variable size at runtime)
 * Author   : PAVAN SHETTY H S
 * Topic    : Dynamic Memory Allocation
 *
 * Sometimes we don't know array size at compile time.
 * Dynamic memory lets us decide size at runtime.
 *
 * Expected Output:
 * Enter number of elements: 4
 * Enter elements: 7 2 9 1
 * Sorted: 1 2 7 9
 */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Allocate exactly n integers at runtime */
    int *arr = (int*) malloc(n * sizeof(int));
    if(!arr) { printf("Allocation failed!\n"); return 1; }

    printf("Enter %d elements: ", n);
    int i;
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    bubble_sort(arr, n);

    printf("Sorted: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
