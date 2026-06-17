/*
 * Program  : Increment and Decrement Operators
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * ++ = increment by 1
 * -- = decrement by 1
 *
 * Pre-increment: ++a (increment first, then use)
 * Post-increment: a++ (use first, then increment)
 *
 * Expected Output:
 * Pre-increment:  b = 11
 * Post-increment: c = 10 (then c becomes 11)
 */

#include <stdio.h>

int main()
{
    int a = 10;
    int b, c;

    /* Pre-increment: increment happens BEFORE the value is used */
    b = ++a;  /* a becomes 11, then b = 11 */
    printf("After pre-increment (b = ++a):\n");
    printf("a = %d, b = %d\n", a, b);

    a = 10;  /* reset */

    /* Post-increment: value is used FIRST, then increment happens */
    c = a++;  /* c = 10 (old value), then a becomes 11 */
    printf("\nAfter post-increment (c = a++):\n");
    printf("a = %d, c = %d\n", a, c);

    /* Common use: counting in loops */
    printf("\n--- Counting LEDs (simulated) ---\n");
    int led_count = 0;
    int i;
    for(i = 0; i < 5; i++)  /* i++ is post-increment here */
    {
        led_count++;
        printf("LED %d turned ON\n", led_count);
    }

    /* Decrement example */
    printf("\n--- Countdown ---\n");
    int count = 5;
    while(count > 0)
    {
        printf("Count: %d\n", count);
        count--;  /* decrement */
    }
    printf("Go!\n");

    return 0;
}
