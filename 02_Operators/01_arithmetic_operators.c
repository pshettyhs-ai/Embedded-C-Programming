/*
 * Program  : Arithmetic Operators in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * Expected Output:
 * a = 10, b = 3
 * Addition: 13
 * Subtraction: 7
 * Multiplication: 30
 * Division: 3
 * Modulo: 1
 */

#include <stdio.h>

int main()
{
    int a = 10, b = 3;

    printf("a = %d, b = %d\n", a, b);
    printf("Addition:       a + b = %d\n", a + b);
    printf("Subtraction:    a - b = %d\n", a - b);
    printf("Multiplication: a * b = %d\n", a * b);
    printf("Division:       a / b = %d\n", a / b);  /* Integer division! */
    printf("Modulo:         a %% b = %d\n", a % b);  /* Remainder */

    /* Practical embedded use: check if a number is even or odd */
    int number = 7;
    if (number % 2 == 0)
        printf("\n%d is Even\n", number);
    else
        printf("\n%d is Odd\n", number);

    /* Using modulo to stay within array bounds - circular buffer! */
    int buffer_size = 8;
    int index = 0;
    printf("\nCircular buffer index demo:\n");
    int i;
    for(i = 0; i < 12; i++)
    {
        printf("i=%d -> buffer[%d]\n", i, index);
        index = (index + 1) % buffer_size;  /* wrap around 0 to 7 */
    }

    return 0;
}
