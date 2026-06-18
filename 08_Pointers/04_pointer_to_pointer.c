/*
 * Program  : Pointer to Pointer (Double Pointer)
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * A pointer to pointer stores the address of another pointer.
 * Used for: dynamic 2D arrays, modifying pointer in a function.
 *
 * Expected Output:
 * x = 10
 * *ptr = 10
 * **pptr = 10
 */

#include <stdio.h>

int main()
{
    int   x    = 10;
    int  *ptr  = &x;    /* ptr  holds address of x */
    int **pptr = &ptr;  /* pptr holds address of ptr */

    printf("x     = %d\n", x);
    printf("*ptr  = %d\n", *ptr);
    printf("**pptr= %d\n", **pptr);

    printf("\nAddresses:\n");
    printf("Address of x   : %p\n", &x);
    printf("ptr  contains  : %p (same as &x)\n", ptr);
    printf("Address of ptr : %p\n", &ptr);
    printf("pptr contains  : %p (same as &ptr)\n", pptr);

    /* Modify x through double pointer */
    **pptr = 99;
    printf("\nAfter **pptr = 99: x = %d\n", x);

    return 0;
}
