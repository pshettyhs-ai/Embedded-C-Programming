/*
 * Program  : inline Functions and Macros in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Functions
 *
 * inline functions are placed in-line where called.
 * No function call overhead — faster execution.
 * Very important in embedded for time-critical code!
 *
 * Expected Output:
 * Max of 10, 20 = 20
 * Min of 10, 20 = 10
 */

#include <stdio.h>

/* inline function example */
static inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

static inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

/* Macro-based function (also no call overhead) */
#define ABS(x)     ((x) < 0 ? -(x) : (x))
#define SQUARE(x)  ((x) * (x))

/* Embedded: bit manipulation as inline */
static inline void set_bit(unsigned char *reg, int bit)
{
    *reg |= (1 << bit);
}

static inline void clear_bit(unsigned char *reg, int bit)
{
    *reg &= ~(1 << bit);
}

static inline int read_bit(unsigned char reg, int bit)
{
    return (reg >> bit) & 1;
}

int main()
{
    printf("Max of 10, 20 = %d\n", max(10, 20));
    printf("Min of 10, 20 = %d\n", min(10, 20));

    printf("ABS(-15)  = %d\n", ABS(-15));
    printf("SQUARE(7) = %d\n", SQUARE(7));

    /* Bit manipulation example */
    unsigned char reg = 0x00;
    printf("\n--- Register Bit Operations ---\n");
    printf("Initial reg: 0x%02X\n", reg);

    set_bit(&reg, 3);
    printf("After set_bit(3): 0x%02X\n", reg);

    set_bit(&reg, 0);
    printf("After set_bit(0): 0x%02X\n", reg);

    printf("Bit 3 value: %d\n", read_bit(reg, 3));
    printf("Bit 1 value: %d\n", read_bit(reg, 1));

    clear_bit(&reg, 3);
    printf("After clear_bit(3): 0x%02X\n", reg);

    return 0;
}
