/*
 * Program  : Count Set Bits (Population Count)
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * Count how many bits are 1 in a number.
 * This is called "Hamming Weight" or "Population Count".
 * Asked a lot in embedded interviews!
 *
 * Expected Output:
 * Set bits in 0xA5 (10100101) = 4
 */

#include <stdio.h>

/* Method 1: Check each bit one by one */
int count_bits_method1(unsigned int n)
{
    int count = 0;
    while(n)
    {
        count += (n & 1);  /* check LSB */
        n >>= 1;           /* shift right */
    }
    return count;
}

/* Method 2: Brian Kernighan's trick (faster!) */
/* n & (n-1) clears the lowest set bit each time */
int count_bits_method2(unsigned int n)
{
    int count = 0;
    while(n)
    {
        n &= (n - 1);  /* clear lowest set bit */
        count++;
    }
    return count;
}

int main()
{
    unsigned char values[] = {0x00, 0xFF, 0xA5, 0x0F, 0x55, 0xAA};
    int n = 6, i;

    printf("%-6s  %-10s  M1  M2\n", "Value", "Binary");
    printf("------  ----------  --  --\n");

    for(i = 0; i < n; i++)
    {
        unsigned char v = values[i];
        printf("0x%02X    ", v);
        int j;
        for(j = 7; j >= 0; j--) printf("%d", (v >> j) & 1);
        printf("  %2d  %2d\n",
               count_bits_method1(v),
               count_bits_method2(v));
    }

    /* Practical embedded use: count how many GPIO pins are HIGH */
    printf("\n--- Counting HIGH GPIO pins ---\n");
    unsigned char gpio_port = 0b10110101;  /* some pins are HIGH */
    printf("GPIO Port: 0b");
    int j;
    for(j = 7; j >= 0; j--) printf("%d", (gpio_port >> j) & 1);
    printf("\n");
    printf("Number of HIGH pins: %d\n", count_bits_method2(gpio_port));

    return 0;
}
