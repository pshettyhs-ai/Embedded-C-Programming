/*
 * Program  : while Loop in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * while loop: condition is checked BEFORE each iteration.
 * Used when we don't know in advance how many times to loop.
 *
 * Expected Output:
 * Enter numbers (0 to stop): 5 3 8 0
 * Sum = 16, Count = 3
 */

#include <stdio.h>

int main()
{
    int num, sum = 0, count = 0;

    printf("Enter numbers (enter 0 to stop):\n");

    scanf("%d", &num);
    while(num != 0)  /* loop until user enters 0 */
    {
        sum   += num;
        count++;
        scanf("%d", &num);
    }

    printf("Sum = %d, Count = %d\n", sum, count);
    if(count > 0)
        printf("Average = %.2f\n", (float)sum / count);

    /* Embedded: Waiting for a flag to be set (polling) */
    printf("\n--- Polling Example (simulated) ---\n");
    int flag = 0;
    int timeout = 10;  /* max 10 retries */
    int retry = 0;

    /* In real embedded code: while(!(UART_STATUS & RX_READY)); */
    while(!flag && retry < timeout)
    {
        retry++;
        printf("Waiting for flag... attempt %d\n", retry);
        if(retry == 5) flag = 1;  /* simulate flag being set */
    }

    if(flag)
        printf("Flag received! Proceeding.\n");
    else
        printf("Timeout! Flag not received.\n");

    return 0;
}
