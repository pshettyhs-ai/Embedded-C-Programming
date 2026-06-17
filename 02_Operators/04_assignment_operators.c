/*
 * Program  : Assignment Operators in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * Assignment operators: =, +=, -=, *=, /=, %=
 * Also compound bitwise: &=, |=, ^=, <<=, >>=
 *
 * Expected Output:
 * Initial: a = 10
 * After +=5: a = 15
 * After -=3: a = 12
 * After *=2: a = 24
 */

#include <stdio.h>

int main()
{
    int a = 10;
    printf("Initial: a = %d\n", a);

    a += 5;   /* same as: a = a + 5 */
    printf("After +=5: a = %d\n", a);

    a -= 3;   /* same as: a = a - 3 */
    printf("After -=3: a = %d\n", a);

    a *= 2;   /* same as: a = a * 2 */
    printf("After *=2: a = %d\n", a);

    a /= 4;   /* same as: a = a / 4 */
    printf("After /=4: a = %d\n", a);

    a %= 3;   /* same as: a = a % 3 */
    printf("After %%=3: a = %d\n", a);

    /* Bitwise assignment - very common in embedded for register manipulation */
    unsigned char reg = 0b00000000;  /* 8-bit register, all bits = 0 */
    printf("\n--- Bitwise Assignment (Register Manipulation) ---\n");
    printf("Initial reg: 0x%02X\n", reg);

    reg |= 0x01;   /* Set bit 0  */
    printf("After |=0x01 (set bit0):   0x%02X\n", reg);

    reg |= 0x04;   /* Set bit 2 */
    printf("After |=0x04 (set bit2):   0x%02X\n", reg);

    reg &= ~0x01;  /* Clear bit 0 */
    printf("After &=~0x01 (clr bit0):  0x%02X\n", reg);

    reg ^= 0x04;   /* Toggle bit 2 */
    printf("After ^=0x04 (toggle bit2): 0x%02X\n", reg);

    return 0;
}
