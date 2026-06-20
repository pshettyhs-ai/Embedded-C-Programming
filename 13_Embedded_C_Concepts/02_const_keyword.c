/*
 * Program  : const Keyword in Embedded C
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * const = the value cannot be changed after initialization.
 * In embedded: lookup tables stored in Flash (ROM), not RAM.
 * Saves precious RAM on small MCUs!
 *
 * Different combinations:
 * const int *ptr        = pointer to const int (value can't change)
 * int * const ptr       = const pointer (address can't change)
 * const int * const ptr = both const
 *
 * Expected Output:
 * Sine table values and const pointer demo
 */

#include <stdio.h>
#include <stdint.h>

/* const array: stored in Flash, saves RAM! */
const uint8_t SINE_TABLE[] = {
    0, 25, 49, 71, 90, 106, 118, 127,
    127, 118, 106, 90, 71, 49, 25, 0
};

/* const lookup table for 7-segment display */
const uint8_t SEVEN_SEG[] = {
    0x3F, /* 0 */
    0x06, /* 1 */
    0x5B, /* 2 */
    0x4F, /* 3 */
    0x66, /* 4 */
    0x6D, /* 5 */
    0x7D, /* 6 */
    0x07, /* 7 */
    0x7F, /* 8 */
    0x6F  /* 9 */
};

int main()
{
    printf("=== const Keyword Demo ===\n\n");

    /* Accessing const array (Flash, not RAM) */
    printf("Sine lookup table (16 values):\n");
    int i;
    for(i = 0; i < 16; i++)
        printf("%3d", SINE_TABLE[i]);
    printf("\n");

    /* 7-segment display codes */
    printf("\n7-Segment codes:\n");
    for(i = 0; i < 10; i++)
        printf("Digit %d = 0x%02X\n", i, SEVEN_SEG[i]);

    /* const pointer examples */
    printf("\n--- Pointer and const combinations ---\n");
    int a = 10, b = 20;

    /* 1. Pointer to const: can change where we point, but not the value */
    const int *p1 = &a;
    printf("const int *p1: *p1=%d\n", *p1);
    p1 = &b;               /* OK: can change the address */
    printf("After p1=&b:   *p1=%d\n", *p1);
    /* *p1 = 30;  ERROR: cannot change the value through this pointer */

    /* 2. Const pointer: cannot change where we point, but can change value */
    int * const p2 = &a;
    *p2 = 50;              /* OK: can change the value */
    printf("\nint* const p2: *p2=%d, a=%d\n", *p2, a);
    /* p2 = &b;  ERROR: cannot change the pointer itself */

    /* 3. volatile const: read-only hardware register */
    printf("\nvolatile const: used for read-only hardware registers\n");
    printf("e.g., volatile const uint32_t *GPIO_IDR = (uint32_t*)0x40020010;\n");

    return 0;
}
