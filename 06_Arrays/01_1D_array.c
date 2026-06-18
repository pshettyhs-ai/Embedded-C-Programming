/*
 * Program  : 1D Array Basics
 * Author   : PAVAN SHETTY H S
 * Topic    : Arrays
 *
 * An array stores multiple values of the same type.
 * In embedded: storing ADC readings, UART buffer, lookup tables.
 *
 * Expected Output:
 * Array elements: 10 20 30 40 50
 * Sum = 150, Average = 30.00
 */

#include <stdio.h>

int main()
{
    /* Array declaration and initialization */
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;  /* size of array */
    int i, sum = 0;

    /* Print all elements */
    printf("Array elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* Find sum and average */
    for(i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum / n);

    /* Find max and min */
    int max = arr[0], min = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    /* Embedded Example: ADC readings buffer */
    printf("\n--- ADC Readings Buffer ---\n");
    unsigned int adc_buf[8] = {512, 480, 530, 490, 515, 488, 520, 500};
    unsigned int adc_sum = 0;

    for(i = 0; i < 8; i++)
    {
        adc_sum += adc_buf[i];
        printf("Reading[%d] = %u (%.2fV)\n", i, adc_buf[i],
               (float)adc_buf[i] / 1023.0f * 5.0f);
    }
    printf("Average ADC = %u (%.2fV)\n", adc_sum/8,
           (float)(adc_sum/8) / 1023.0f * 5.0f);

    return 0;
}
