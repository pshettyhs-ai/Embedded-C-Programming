/*
 * Program  : Passing Arrays to Functions
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * When you pass an array to a function, the array name is a POINTER.
 * So changes inside the function DO affect the original array!
 *
 * Expected Output:
 * Before: 1 2 3 4 5
 * After doubling: 2 4 6 8 10
 */

#include <stdio.h>

/* Array passed as pointer - changes affect original */
void double_array(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        arr[i] *= 2;
}

int sum_array(int arr[], int n)
{
    int i, sum = 0;
    for(i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

void fill_array(int arr[], int n, int value)
{
    int i;
    for(i = 0; i < n; i++)
        arr[i] = value;
}

void print_array(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Before: "); print_array(arr, n);

    double_array(arr, n);
    printf("After doubling: "); print_array(arr, n);

    printf("Sum = %d\n", sum_array(arr, n));

    int buf[5];
    fill_array(buf, 5, 0);  /* initialize buffer to 0 */
    printf("Zeroed buffer: "); print_array(buf, 5);

    /* Embedded: Circular buffer (FIFO) for UART */
    printf("\n--- Circular Buffer Demo ---\n");
    unsigned char uart_buf[8];
    int head = 0, tail = 0, count = 0;

    /* Enqueue (write) */
    uart_buf[head] = 'H'; head = (head + 1) % 8; count++;
    uart_buf[head] = 'i'; head = (head + 1) % 8; count++;
    uart_buf[head] = '!'; head = (head + 1) % 8; count++;

    /* Dequeue (read) */
    printf("Reading from UART buffer: ");
    while(count > 0)
    {
        printf("%c", uart_buf[tail]);
        tail = (tail + 1) % 8;
        count--;
    }
    printf("\n");

    return 0;
}
