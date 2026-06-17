/*
 * Program  : Storage Classes in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Basics of C
 *
 * Description:
 * Storage classes define the scope, visibility, and lifetime of variables.
 * This is very important in embedded C programming!
 *
 * 4 Storage Classes:
 * 1. auto    - default for local variables
 * 2. register- stored in CPU register (faster access)
 * 3. static  - retains value between function calls
 * 4. extern  - declared outside, used in multiple files
 *
 * Expected Output:
 * auto variable: 10
 * Static count: 1
 * Static count: 2
 * Static count: 3
 */

#include <stdio.h>

/* Global variable - accessible everywhere in this file */
int global_var = 100;

/* Static global - only accessible in this file */
static int file_private = 50;

void counter_function()
{
    /* static variable - keeps its value between calls! */
    static int count = 0;
    count++;
    printf("Static count: %d\n", count);
}

void auto_example()
{
    /* auto is the default - local variables are auto */
    auto int x = 10;   /* 'auto' keyword is rarely written explicitly */
    printf("auto variable: %d\n", x);
    /* x is destroyed when this function ends */
}

void register_example()
{
    /* register tells compiler to store in CPU register if possible */
    /* Useful in loops in embedded systems for faster execution */
    register int i;
    int sum = 0;
    for(i = 0; i < 10; i++)
    {
        sum += i;
    }
    printf("Sum using register variable: %d\n", sum);
}

int main()
{
    auto_example();
    
    /* Call counter 3 times to see static behavior */
    counter_function();
    counter_function();
    counter_function();

    register_example();

    printf("Global variable: %d\n", global_var);
    printf("File-private static: %d\n", file_private);

    /* Interview Notes:
     * Q: What is a static variable in embedded C?
     * A: A static local variable retains its value between function calls.
     *    Static global variables are limited in scope to the file they are in.
     *    Very useful for ISR (Interrupt Service Routine) flags!
     *
     * Q: Why is 'volatile' not a storage class?
     * A: volatile is a type qualifier, not a storage class.
     *    It tells the compiler not to optimize reads/writes to that variable.
     *    Used for hardware registers and ISR-shared variables.
     */

    return 0;
}
