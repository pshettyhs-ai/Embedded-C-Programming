/*
 * Program  : Bitwise Operators in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * Bitwise operators work on individual bits.
 * THIS IS THE MOST IMPORTANT TOPIC FOR EMBEDDED SYSTEMS!
 * We use bitwise ops to configure registers on microcontrollers.
 *
 * Operators:
 * &  = AND   (both bits must be 1)
 * |  = OR    (at least one bit is 1)
 * ^  = XOR   (bits must be different)
 * ~  = NOT   (invert all bits)
 * << = Left shift
 * >> = Right shift
 *
 * Expected Output:
 * a & b = 0x0C
 * a | b = 0x3E
 * a ^ b = 0x32
 */

#include <stdio.h>

/* Helper to print binary representation */
void print_binary(unsigned char val)
{
    int i;
    printf("0b");
    for(i = 7; i >= 0; i--)
        printf("%d", (val >> i) & 1);
}

int main()
{
    unsigned char a = 0x3C;  /* 0011 1100 */
    unsigned char b = 0x0F;  /* 0000 1111 */

    printf("a = 0x%02X = ", a); print_binary(a); printf("\n");
    printf("b = 0x%02X = ", b); print_binary(b); printf("\n\n");

    printf("a & b = 0x%02X = ", a & b); print_binary(a & b); printf("  (AND)\n");
    printf("a | b = 0x%02X = ", a | b); print_binary(a | b); printf("  (OR)\n");
    printf("a ^ b = 0x%02X = ", a ^ b); print_binary(a ^ b); printf("  (XOR)\n");
    printf("~a    = 0x%02X = ", (unsigned char)~a);
    print_binary((unsigned char)~a); printf("  (NOT)\n");

    printf("\n--- Shift Operations ---\n");
    unsigned char x = 0x01;  /* 0000 0001 */
    printf("x       = "); print_binary(x); printf("\n");
    printf("x << 1  = "); print_binary(x << 1); printf("  (shift left  = multiply by 2)\n");
    printf("x << 3  = "); print_binary(x << 3); printf("  (shift left  3 = multiply by 8)\n");

    unsigned char y = 0x80;  /* 1000 0000 */
    printf("\ny       = "); print_binary(y); printf("\n");
    printf("y >> 1  = "); print_binary(y >> 1); printf("  (shift right = divide by 2)\n");
    printf("y >> 4  = "); print_binary(y >> 4); printf("  (shift right 4 = divide by 16)\n");

    return 0;
}
