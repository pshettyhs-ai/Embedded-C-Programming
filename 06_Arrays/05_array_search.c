/*
 * Program  : Searching in Arrays
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * Linear Search: check each element one by one - O(n)
 * Binary Search: works on SORTED arrays only - O(log n)
 *
 * Expected Output:
 * Linear Search: Found 25 at index 2
 * Binary Search: Found 25 at index 2
 */

#include <stdio.h>

/* Linear Search: works on any array */
int linear_search(int arr[], int n, int target)
{
    int i;
    for(i = 0; i < n; i++)
        if(arr[i] == target)
            return i;  /* return index */
    return -1;         /* not found */
}

/* Binary Search: only works on SORTED array */
int binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1, mid;

    while(left <= right)
    {
        mid = (left + right) / 2;  /* find middle */

        if(arr[mid] == target)     return mid;   /* found! */
        else if(arr[mid] < target) left = mid + 1;  /* search right half */
        else                       right = mid - 1; /* search left half */
    }
    return -1;  /* not found */
}

int main()
{
    int arr[] = {11, 12, 22, 25, 34, 64, 90};  /* sorted array */
    int n = 7;
    int target = 25;
    int result;

    printf("Array: ");
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    /* Linear Search */
    result = linear_search(arr, n, target);
    if(result != -1)
        printf("Linear Search: Found %d at index %d\n", target, result);
    else
        printf("Linear Search: %d not found\n", target);

    /* Binary Search */
    result = binary_search(arr, n, target);
    if(result != -1)
        printf("Binary Search: Found %d at index %d\n", target, result);
    else
        printf("Binary Search: %d not found\n", target);

    /* Search for non-existing element */
    result = binary_search(arr, n, 50);
    printf("Searching 50: %s\n", (result == -1) ? "Not found" : "Found");

    return 0;
}
