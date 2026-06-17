/*
 * Program  : break and continue Statements
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * break    : exits the loop immediately
 * continue : skips current iteration, goes to next
 *
 * Expected Output:
 * (see below)
 */

#include <stdio.h>

int main()
{
    int i;

    /* break example: stop when we find 5 */
    printf("--- break example ---\n");
    printf("Searching for value 5 in array...\n");
    int arr[] = {2, 7, 3, 5, 8, 1};
    int n = 6, found = 0;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == 5)
        {
            printf("Found 5 at index %d!\n", i);
            found = 1;
            break;  /* stop searching, no need to continue */
        }
        printf("Checking arr[%d] = %d...\n", i, arr[i]);
    }
    if(!found) printf("Value not found.\n");

    /* continue example: skip even numbers, print only odd */
    printf("\n--- continue example ---\n");
    printf("Odd numbers from 1 to 10: ");
    for(i = 1; i <= 10; i++)
    {
        if(i % 2 == 0)
            continue;  /* skip even numbers */
        printf("%d ", i);
    }
    printf("\n");

    /* Embedded Example: Read sensor data, skip invalid readings */
    printf("\n--- Sensor data (skip readings > 100) ---\n");
    int sensor_data[] = {45, 120, 67, 255, 33, 89, 150, 72};
    int data_size = 8;
    int valid_sum = 0, valid_count = 0;

    for(i = 0; i < data_size; i++)
    {
        if(sensor_data[i] > 100)
        {
            printf("Skipping invalid data: %d\n", sensor_data[i]);
            continue;  /* skip this reading */
        }
        valid_sum += sensor_data[i];
        valid_count++;
        printf("Valid data: %d\n", sensor_data[i]);
    }

    printf("Valid readings: %d, Average: %.1f\n",
           valid_count, (float)valid_sum / valid_count);

    return 0;
}
