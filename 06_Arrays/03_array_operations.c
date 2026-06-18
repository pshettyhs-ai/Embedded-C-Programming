/*
 * Program  : Array Operations
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * Common array operations: insert, delete, reverse
 *
 * Expected Output:
 * Original: 1 2 3 4 5
 * Reversed: 5 4 3 2 1
 */

#include <stdio.h>

void print_array(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverse_array(int arr[], int n)
{
    int i, temp;
    for(i = 0; i < n/2; i++)
    {
        temp       = arr[i];
        arr[i]     = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

/* Insert element at position */
int insert(int arr[], int *n, int pos, int value, int max_size)
{
    if(*n >= max_size) return -1;  /* array full */
    int i;
    for(i = *n; i > pos; i--)     /* shift right */
        arr[i] = arr[i-1];
    arr[pos] = value;
    (*n)++;
    return 0;
}

/* Delete element at position */
void delete_at(int arr[], int *n, int pos)
{
    int i;
    for(i = pos; i < *n - 1; i++)  /* shift left */
        arr[i] = arr[i+1];
    (*n)--;
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Original:  "); print_array(arr, n);

    reverse_array(arr, n);
    printf("Reversed:  "); print_array(arr, n);

    reverse_array(arr, n); /* reverse back */

    insert(arr, &n, 2, 99, 20);
    printf("After insert 99 at index 2: "); print_array(arr, n);

    delete_at(arr, &n, 2);
    printf("After delete at index 2:    "); print_array(arr, n);

    return 0;
}
