/*
 * Program  : Check Bit Status and Bit Masking
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * Checking bits is used when reading sensor status registers,
 * interrupt flags, peripheral status flags, etc.
 *
 * Expected Output:
 * UART Status register: 0x85
 * RX data ready: YES
 * TX buffer empty: YES
 * Parity error: NO
 */

#include <stdio.h>

/* Simulated UART Status Register bit positions */
#define UART_RX_READY   0   /* bit 0: data received */
#define UART_TX_EMPTY   1   /* bit 1: transmit buffer empty */
#define UART_PARITY_ERR 2   /* bit 2: parity error */
#define UART_FRAME_ERR  3   /* bit 3: frame error */
#define UART_OVERFLOW   4   /* bit 4: receive overflow */

#define CHECK_BIT(reg, bit)  (((reg) >> (bit)) & 1)

int main()
{
    /* Simulated UART status register value */
    unsigned char UART_SR = 0x85;  /* 1000 0101 */
    printf("UART Status Register: 0x%02X\n\n", UART_SR);

    /* Check individual bits */
    printf("RX data ready    : %s\n", CHECK_BIT(UART_SR, UART_RX_READY)   ? "YES" : "NO");
    printf("TX buffer empty  : %s\n", CHECK_BIT(UART_SR, UART_TX_EMPTY)   ? "YES" : "NO");
    printf("Parity error     : %s\n", CHECK_BIT(UART_SR, UART_PARITY_ERR) ? "YES" : "NO");
    printf("Frame error      : %s\n", CHECK_BIT(UART_SR, UART_FRAME_ERR)  ? "YES" : "NO");
    printf("Overflow error   : %s\n", CHECK_BIT(UART_SR, UART_OVERFLOW)   ? "YES" : "NO");

    /* Bit masking: extract only certain bits */
    printf("\n--- Bit Masking ---\n");
    unsigned char data = 0xB7;  /* 1011 0111 */
    unsigned char lower_nibble = data & 0x0F;  /* mask lower 4 bits */
    unsigned char upper_nibble = (data >> 4) & 0x0F;  /* get upper 4 bits */

    printf("data         = 0x%02X\n", data);
    printf("Lower nibble = 0x%X\n",   lower_nibble);
    printf("Upper nibble = 0x%X\n",   upper_nibble);

    /* Check even/odd using bit 0 */
    int num = 47;
    printf("\n%d is %s (bit0=%d)\n", num,
           (num & 1) ? "ODD" : "EVEN", num & 1);

    return 0;
}
