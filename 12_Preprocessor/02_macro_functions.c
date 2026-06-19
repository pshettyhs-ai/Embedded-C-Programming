/*
 * Program  : Function-like Macros
 * Author   : PAVAN SHETTY H S
 * Topic    : Preprocessor Directives
 *
 * Macros can behave like functions but are faster (no call overhead).
 * Warning: Always wrap arguments in parentheses to avoid bugs!
 *
 * Expected Output:
 * MAX(10, 20) = 20
 * SQUARE(5) = 25
 * SET_BIT result: 0x08
 */

#include <stdio.h>

/* Function-like macros */
#define MAX(a, b)         ((a) > (b) ? (a) : (b))
#define MIN(a, b)         ((a) < (b) ? (a) : (b))
#define ABS(x)            ((x) < 0 ? -(x) : (x))
#define SQUARE(x)         ((x) * (x))
#define CUBE(x)           ((x) * (x) * (x))

/* Bit manipulation macros (used in EVERY embedded project!) */
#define SET_BIT(reg, n)   ((reg) |=  (1U << (n)))
#define CLEAR_BIT(reg, n) ((reg) &= ~(1U << (n)))
#define TOGGLE_BIT(reg,n) ((reg) ^=  (1U << (n)))
#define READ_BIT(reg, n)  (((reg) >> (n)) & 1U)

/* Useful utility macros */
#define ARRAY_SIZE(arr)   (sizeof(arr) / sizeof((arr)[0]))
#define BIT(n)            (1U << (n))

int main()
{
    printf("MAX(10, 20)     = %d\n", MAX(10, 20));
    printf("MIN(10, 20)     = %d\n", MIN(10, 20));
    printf("ABS(-15)        = %d\n", ABS(-15));
    printf("SQUARE(7)       = %d\n", SQUARE(7));
    printf("CUBE(3)         = %d\n", CUBE(3));

    /* Bit manipulation */
    unsigned char reg = 0x00;
    printf("\n--- Bit Macros ---\n");
    printf("Initial reg: 0x%02X\n", reg);

    SET_BIT(reg, 3);
    printf("After SET_BIT(3):    0x%02X\n", reg);

    SET_BIT(reg, 0);
    printf("After SET_BIT(0):    0x%02X\n", reg);

    TOGGLE_BIT(reg, 3);
    printf("After TOGGLE_BIT(3): 0x%02X\n", reg);

    CLEAR_BIT(reg, 0);
    printf("After CLEAR_BIT(0):  0x%02X\n", reg);

    printf("READ_BIT(reg, 0): %d\n", READ_BIT(reg, 0));
    printf("READ_BIT(reg, 3): %d\n", READ_BIT(reg, 3));

    /* ARRAY_SIZE macro */
    int arr[] = {10, 20, 30, 40, 50};
    printf("\nArray size: %lu\n", ARRAY_SIZE(arr));

    return 0;
}
