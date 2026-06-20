/*
 * Program  : register Keyword and Storage Classes in Embedded C
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * register = hint to compiler to store variable in CPU register.
 * Faster access than RAM. Good for loop counters, frequently used vars.
 * Note: Modern compilers often ignore this and optimize automatically.
 * But still asked in interviews!
 *
 * Expected Output:
 * Loop with register variable (fast)
 */

#include <stdio.h>
#include <time.h>

int main()
{
    printf("=== register and Storage Classes ===\n\n");

    /* register variable example */
    register int i;   /* hint: store in CPU register */
    int sum = 0;

    printf("1. register variable in loop:\n");
    for(i = 0; i < 100; i++)
        sum += i;
    printf("   Sum 0-99 = %d\n", sum);

    /* auto (default for local variables) */
    printf("\n2. auto variable (default):\n");
    {
        auto int local_x = 42;  /* 'auto' is redundant but shows intent */
        printf("   auto int: %d\n", local_x);
    }
    /* local_x is gone here */

    /* static local: retains value between calls */
    printf("\n3. static local variable:\n");
    void counter_demo(void);  /* forward declaration */
    counter_demo();
    counter_demo();
    counter_demo();

    /* extern (declared in another file, shown conceptually) */
    printf("\n4. extern usage (conceptual):\n");
    printf("   In file1.c: int shared_var = 100;\n");
    printf("   In file2.c: extern int shared_var; // use it here\n");
    printf("   This allows sharing global vars across .c files\n");

    return 0;
}

void counter_demo(void)
{
    static int count = 0;  /* initialized only once! */
    count++;
    printf("   Call count: %d\n", count);
}
