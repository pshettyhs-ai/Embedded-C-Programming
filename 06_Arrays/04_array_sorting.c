/*
 * Program  : Sorting Arrays in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * Bubble Sort and Selection Sort
 * These are commonly asked in interviews!
 *
 * Expected Output:
 * Unsorted: 64 34 25 12 22 11 90
 * Bubble Sort: 11 12 22 25 34 64 90
 */

#include <stdio.h>

void print_array(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* Bubble Sort - O(n^2) */
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])  /* swap if out of order */
            {
                temp     = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Selection Sort - O(n^2) */
void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++)
    {
        min_idx = i;  /* assume current position has min */
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;  /* found smaller element */
        }
        /* Swap minimum with current position */
        temp          = arr[min_idx];
        arr[min_idx]  = arr[i];
        arr[i]        = temp;
    }
}

int main()
{
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    printf("Unsorted:       "); print_array(arr1, n);

    bubble_sort(arr1, n);
    printf("Bubble Sort:    "); print_array(arr1, n);

    selection_sort(arr2, n);
    printf("Selection Sort: "); print_array(arr2, n);

    return 0;
}
