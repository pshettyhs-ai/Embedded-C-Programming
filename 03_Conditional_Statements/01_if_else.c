/*
 * Program  : if-else Statement
 * Author   : PAVAN SHETTY H S
 * Topic    : Conditional Statements
 *
 * Expected Output:
 * Enter a number: 15
 * 15 is Positive
 * 15 is Odd
 */

#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    /* Check positive, negative, or zero */
    if (num > 0)
        printf("%d is Positive\n", num);
    else if (num < 0)
        printf("%d is Negative\n", num);
    else
        printf("Number is Zero\n");

    /* Check even or odd */
    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);

    return 0;
}
