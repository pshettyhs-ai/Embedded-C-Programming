/*
 * Program  : for Loop in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * Syntax: for(init; condition; update) { body }
 *
 * Expected Output:
 * 1 2 3 4 5 6 7 8 9 10
 * Sum = 55
 */

#include <stdio.h>

int main()
{
    int i, sum = 0;

    /* Basic for loop */
    printf("Numbers 1 to 10: ");
    for(i = 1; i <= 10; i++)
    {
        printf("%d ", i);
        sum += i;
    }
    printf("\nSum = %d\n", sum);

    /* Countdown - used in delay loops in embedded */
    printf("\nCountdown: ");
    for(i = 10; i >= 0; i--)
        printf("%d ", i);
    printf("\nBlast Off!\n");

    /* Table of 5 */
    printf("\nTable of 5:\n");
    for(i = 1; i <= 10; i++)
        printf("5 x %2d = %2d\n", i, 5 * i);

    /* Embedded: Scanning all 8 bits of a byte */
    unsigned char reg = 0xA5;  /* 10100101 */
    printf("\nBit pattern of 0x%02X: ", reg);
    for(i = 7; i >= 0; i--)
    {
        printf("%d", (reg >> i) & 1);  /* print each bit */
        if(i == 4) printf(" ");        /* space in middle for readability */
    }
    printf("\n");

    return 0;
}
