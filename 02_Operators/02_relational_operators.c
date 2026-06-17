/*
 * Program  : Relational Operators in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * Relational operators compare two values.
 * Result is always 1 (true) or 0 (false).
 *
 * Expected Output:
 * a=10, b=20
 * a == b : 0
 * a != b : 1
 * a > b  : 0
 * a < b  : 1
 * a >= b : 0
 * a <= b : 1
 */

#include <stdio.h>

int main()
{
    int a = 10, b = 20;

    printf("a = %d, b = %d\n\n", a, b);
    printf("a == b : %d\n", a == b);   /* Equal to */
    printf("a != b : %d\n", a != b);   /* Not equal */
    printf("a >  b : %d\n", a > b);    /* Greater than */
    printf("a <  b : %d\n", a < b);    /* Less than */
    printf("a >= b : %d\n", a >= b);   /* Greater or equal */
    printf("a <= b : %d\n", a <= b);   /* Less or equal */

    /* Embedded Example: Compare temperature sensor reading */
    int temperature = 75;  /* degrees Celsius */
    int threshold   = 80;

    printf("\n--- Temperature Check ---\n");
    printf("Temperature: %d C, Threshold: %d C\n", temperature, threshold);

    if (temperature >= threshold)
        printf("WARNING: Overheating! Activate cooling!\n");
    else
        printf("Temperature is safe.\n");

    return 0;
}
