/*
 * Program  : Swap Two Numbers Using XOR
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * XOR trick to swap without a temp variable.
 * This is a very popular interview question!
 *
 * How it works:
 * a = a ^ b
 * b = a ^ b  (now b has original a)
 * a = a ^ b  (now a has original b)
 *
 * Expected Output:
 * Before: a=10, b=20
 * After XOR swap: a=20, b=10
 */

#include <stdio.h>

int main()
{
    int a = 10, b = 20;

    printf("Before swap: a = %d, b = %d\n", a, b);

    /* XOR swap - no temp variable needed! */
    a = a ^ b;
    b = a ^ b;  /* b = (a^b)^b = a */
    a = a ^ b;  /* a = (a^b)^a = b */

    printf("After XOR swap: a = %d, b = %d\n", a, b);

    /* Regular swap with temp (for comparison) */
    int x = 100, y = 200;
    printf("\nRegular swap:\n");
    printf("Before: x=%d, y=%d\n", x, y);
    int temp = x;
    x = y;
    y = temp;
    printf("After:  x=%d, y=%d\n", x, y);

    /* Check power of 2 using XOR and AND */
    printf("\n--- Check if number is power of 2 ---\n");
    int nums[] = {1, 2, 3, 4, 7, 8, 16, 15};
    int count = 8, i;
    for(i = 0; i < count; i++)
    {
        /* n & (n-1) == 0 means it's a power of 2 */
        if(nums[i] > 0 && (nums[i] & (nums[i]-1)) == 0)
            printf("%2d is a power of 2\n", nums[i]);
        else
            printf("%2d is NOT a power of 2\n", nums[i]);
    }

    return 0;
}
