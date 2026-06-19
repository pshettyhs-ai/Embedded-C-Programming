/*
 * Program  : Set, Clear, Toggle a Bit (GPIO Register Operations)
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * This is THE most important embedded C skill!
 * Every time you configure a GPIO, UART, Timer register,
 * you use these bit operations.
 *
 * SET   bit n : reg |=  (1 << n)
 * CLEAR bit n : reg &= ~(1 << n)
 * TOGGLE bit n: reg ^=  (1 << n)
 * READ  bit n : (reg >>  n) & 1
 *
 * Expected Output:
 * Initial  : 0x00 = 0b00000000
 * Set bit3 : 0x08 = 0b00001000
 * Set bit0 : 0x09 = 0b00001001
 * Clear bit3: 0x01 = 0b00000001
 * Toggle bit0: 0x00 = 0b00000000
 */

#include <stdio.h>

void print_reg(const char *label, unsigned char reg)
{
    printf("%-14s: 0x%02X = 0b", label, reg);
    int i;
    for(i = 7; i >= 0; i--) printf("%d", (reg >> i) & 1);
    printf("\n");
}

int main()
{
    unsigned char GPIO_REG = 0x00;  /* Simulated GPIO register */

    print_reg("Initial", GPIO_REG);

    /* SET bit 3 (turn on LED connected to bit 3) */
    GPIO_REG |= (1 << 3);
    print_reg("Set bit3", GPIO_REG);

    /* SET bit 0 */
    GPIO_REG |= (1 << 0);
    print_reg("Set bit0", GPIO_REG);

    /* SET multiple bits at once */
    GPIO_REG |= (1 << 5) | (1 << 6);
    print_reg("Set b5,b6", GPIO_REG);

    /* CLEAR bit 3 (turn off LED at bit 3) */
    GPIO_REG &= ~(1 << 3);
    print_reg("Clear bit3", GPIO_REG);

    /* CLEAR multiple bits */
    GPIO_REG &= ~((1 << 5) | (1 << 6));
    print_reg("Clr b5,b6", GPIO_REG);

    /* TOGGLE bit 0 (blink LED at bit 0) */
    printf("\n--- Blinking LED (toggle bit0) ---\n");
    int i;
    for(i = 0; i < 6; i++)
    {
        GPIO_REG ^= (1 << 0);
        printf("LED state: %s (reg=0x%02X)\n",
               (GPIO_REG & (1<<0)) ? "ON" : "OFF", GPIO_REG);
    }

    /* READ specific bit */
    printf("\n--- Reading bits ---\n");
    unsigned char STATUS = 0xA5;  /* 1010 0101 */
    for(i = 7; i >= 0; i--)
        printf("Bit[%d] = %d\n", i, (STATUS >> i) & 1);

    return 0;
}
