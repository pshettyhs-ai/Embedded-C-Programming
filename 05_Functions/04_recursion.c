/*
 * Program  : Recursion in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Functions
 *
 * Recursion = a function that calls itself.
 * Must have a BASE CASE to stop (otherwise infinite loop + stack overflow!)
 *
 * Note: In embedded systems, recursion is usually AVOIDED because:
 * - MCUs have very limited stack memory
 * - Risk of stack overflow
 * But it's important for interviews!
 *
 * Expected Output:
 * Factorial of 5 = 120
 * Fibonacci(7) = 13
 */

#include <stdio.h>

/* Factorial using recursion */
int factorial(int n)
{
    if(n == 0 || n == 1)  /* Base case */
        return 1;
    return n * factorial(n - 1);  /* Recursive call */
}

/* Fibonacci using recursion */
int fibonacci(int n)
{
    if(n == 0) return 0;  /* Base case 1 */
    if(n == 1) return 1;  /* Base case 2 */
    return fibonacci(n-1) + fibonacci(n-2);  /* Recursive call */
}

/* Sum of digits recursively */
int sum_of_digits(int n)
{
    if(n == 0) return 0;
    return (n % 10) + sum_of_digits(n / 10);
}

int main()
{
    /* Factorial */
    printf("Factorial of 5 = %d\n", factorial(5));
    printf("Factorial of 0 = %d\n", factorial(0));

    /* Fibonacci */
    printf("\nFibonacci series (first 10 terms):\n");
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    /* Sum of digits */
    int number = 12345;
    printf("\nSum of digits of %d = %d\n", number, sum_of_digits(number));

    /* Warning about embedded usage */
    printf("\nNote: Avoid deep recursion in embedded systems!\n");
    printf("Use iterative solutions to save stack space.\n");

    return 0;
}
