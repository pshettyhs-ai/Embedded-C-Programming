/*
 * Program  : Bit Shifting Operations
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * Left shift  (<<) : multiply by powers of 2
 * Right shift (>>) : divide by powers of 2
 * Also used to move bits to correct positions in registers.
 *
 * Expected Output:
 * 1 << 0  = 1
 * 1 << 1  = 2
 * 1 << 2  = 4
 * 1 << 3  = 8  (powers of 2!)
 */

#include <stdio.h>

int main()
{
    /* Left shift = multiply by 2 each time */
    printf("--- Left Shift (multiply by 2) ---\n");
    int i;
    for(i = 0; i <= 7; i++)
        printf("1 << %d = %d\n", i, 1 << i);

    /* Right shift = divide by 2 */
    printf("\n--- Right Shift (divide by 2) ---\n");
    unsigned int val = 256;
    for(i = 0; i <= 8; i++)
        printf("%d >> %d = %d\n", 256, i, 256 >> i);

    /* Practical: fast multiply/divide using shifts */
    int x = 7;
    printf("\n--- Fast math with shifts ---\n");
    printf("%d * 4  = %d (using %d << 2)\n", x, x*4,  x << 2);
    printf("%d * 8  = %d (using %d << 3)\n", x, x*8,  x << 3);
    printf("%d / 2  = %d (using %d >> 1)\n", 64, 64/2, 64 >> 1);
    printf("%d / 4  = %d (using %d >> 2)\n", 64, 64/4, 64 >> 2);

    /* Embedded: build a register value from individual field values */
    printf("\n--- Build Register Value ---\n");
    /* SPI Control Register (simulated):
     * Bits [7:6] = clock divider (2 bits)
     * Bit  [5]   = master mode
     * Bit  [4]   = CPOL
     * Bit  [3]   = CPHA
     * Bits [2:0] = reserved
     */
    unsigned char clk_div   = 0x02;  /* 2-bit field: value 2 */
    unsigned char master    = 1;
    unsigned char cpol      = 0;
    unsigned char cpha      = 1;

    unsigned char spi_ctrl = (clk_div << 6) | (master << 5) |
                              (cpol << 4)    | (cpha << 3);

    printf("SPI_CTRL built value: 0x%02X\n", spi_ctrl);
    int j;
    printf("Binary: ");
    for(j = 7; j >= 0; j--) printf("%d", (spi_ctrl >> j) & 1);
    printf("\n");

    return 0;
}
