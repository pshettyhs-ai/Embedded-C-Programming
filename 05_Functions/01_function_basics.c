/*
 * Program  : Function Basics in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Functions
 *
 * A function is a block of code that does a specific job.
 * In embedded C, we break code into functions for:
 * - GPIO init, UART init, SPI init, etc.
 * - ISR (Interrupt Service Routines)
 * - Reusable utility functions
 *
 * Expected Output:
 * Sum of 5 and 3 = 8
 * Area of circle with radius 7 = 153.94
 */

#include <stdio.h>

#define PI 3.14159f

/* Function declarations (prototypes) - written before main */
int  add(int a, int b);
float area_of_circle(float radius);
void greet(char *name);
int  factorial(int n);

int main()
{
    /* Call functions */
    int result = add(5, 3);
    printf("Sum of 5 and 3 = %d\n", result);

    float area = area_of_circle(7.0f);
    printf("Area of circle with radius 7 = %.2f\n", area);

    greet("PAVAN SHETTY H S");

    printf("Factorial of 5 = %d\n", factorial(5));

    return 0;
}

/* Function definitions */

/* Function that returns sum of two integers */
int add(int a, int b)
{
    return a + b;
}

/* Function that calculates area of circle */
float area_of_circle(float radius)
{
    return PI * radius * radius;
}

/* void function - doesn't return anything */
void greet(char *name)
{
    printf("Hello, %s! Welcome to Embedded C.\n", name);
}

/* Recursive function for factorial */
int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
