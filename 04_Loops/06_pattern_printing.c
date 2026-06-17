/*
 * Program  : Pattern Printing using Loops
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * Pattern problems are common in C interviews.
 * They test your understanding of nested loops.
 *
 * I practiced these a lot during placement prep!
 */

#include <stdio.h>

int main()
{
    int i, j, n = 5;

    /* Pattern 1: Right triangle */
    printf("Pattern 1: Right Triangle\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    /* Pattern 2: Inverted triangle */
    printf("\nPattern 2: Inverted Triangle\n");
    for(i = n; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    /* Pattern 3: Number pattern */
    printf("\nPattern 3: Number Triangle\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    /* Pattern 4: Diamond (harder!) */
    printf("\nPattern 4: Diamond\n");
    /* Upper half */
    for(i = 1; i <= n; i++)
    {
        for(j = i; j < n; j++) printf("  ");    /* spaces */
        for(j = 1; j <= (2*i - 1); j++) printf("* "); /* stars */
        printf("\n");
    }
    /* Lower half */
    for(i = n-1; i >= 1; i--)
    {
        for(j = n; j > i; j--) printf("  ");    /* spaces */
        for(j = 1; j <= (2*i - 1); j++) printf("* "); /* stars */
        printf("\n");
    }

    return 0;
}
