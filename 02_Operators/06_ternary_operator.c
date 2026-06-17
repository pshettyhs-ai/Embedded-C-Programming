/*
 * Program  : Ternary Operator in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * Syntax: condition ? value_if_true : value_if_false
 * This is a shortcut for simple if-else statements.
 *
 * Expected Output:
 * Maximum of 10 and 20 is: 20
 * LED is: ON
 */

#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    int max;

    /* Find maximum using ternary operator */
    max = (a > b) ? a : b;
    printf("Maximum of %d and %d is: %d\n", a, b, max);

    /* Check even or odd */
    int num = 7;
    printf("%d is: %s\n", num, (num % 2 == 0) ? "Even" : "Odd");

    /* Embedded Example: Check LED status based on pin value */
    int pin_value = 1;  /* 1 = HIGH, 0 = LOW */
    printf("LED is: %s\n", pin_value ? "ON" : "OFF");

    /* Another example: absolute value */
    int x = -15;
    int abs_x = (x < 0) ? -x : x;
    printf("Absolute value of %d is: %d\n", x, abs_x);

    return 0;
}
