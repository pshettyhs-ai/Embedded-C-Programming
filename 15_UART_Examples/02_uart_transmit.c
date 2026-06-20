/*
 * Program  : UART Transmit - Send Data
 * Author   : PAVAN SHETTY H S
 * Topic    : UART Communication
 *
 * Transmitting data over UART:
 * 1. Wait until TX buffer is empty (UDRE flag)
 * 2. Write byte to UDR register
 * 3. Hardware sends it automatically
 *
 * Expected Output:
 * Simulated UART transmission of bytes and strings
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Simulated registers */
static uint8_t SIM_UCSR0A = 0x20;  /* UDRE=1 (TX buffer empty, ready) */
static uint8_t SIM_UDR0   = 0;

#define UDRE0  5   /* TX buffer empty flag */
#define TXC0   6   /* TX complete flag */

/* Simulated TX log */
static uint8_t  tx_log[256];
static int      tx_count = 0;

/* ===== UART Transmit Functions ===== */

/* Transmit a single byte */
void UART_SendByte(uint8_t data)
{
    /* Wait until TX buffer is empty */
    /* In real MCU: while(!(UCSR0A & (1 << UDRE0))); */
    while(!(SIM_UCSR0A & (1 << UDRE0)));  /* polling - wait for ready */

    /* Write data to register - hardware sends it */
    SIM_UDR0 = data;
    tx_log[tx_count++] = data;
    printf("  [TX] Sent byte: 0x%02X ('%c')\n", data,
           (data >= 32 && data < 127) ? data : '?');
}

/* Transmit a string */
void UART_SendString(const char *str)
{
    while(*str)
    {
        UART_SendByte((uint8_t)*str);
        str++;
    }
}

/* Transmit an integer as ASCII */
void UART_SendInt(int num)
{
    char buf[12];
    sprintf(buf, "%d", num);
    UART_SendString(buf);
}

/* Transmit a raw buffer */
void UART_SendBuffer(const uint8_t *buf, uint16_t len)
{
    uint16_t i;
    for(i = 0; i < len; i++)
        UART_SendByte(buf[i]);
}

int main()
{
    printf("=== UART Transmit Demo ===\n\n");

    /* Send individual bytes */
    printf("1. Sending individual bytes:\n");
    UART_SendByte('H');
    UART_SendByte('i');
    UART_SendByte('!');
    UART_SendByte('\r');
    UART_SendByte('\n');

    /* Send a string */
    printf("\n2. Sending string:\n");
    UART_SendString("Hello from PAVAN SHETTY H S\r\n");

    /* Send sensor data formatted */
    printf("\n3. Sending formatted sensor data:\n");
    int temperature = 36;
    float voltage   = 3.28f;
    char msg[64];
    sprintf(msg, "TEMP=%d VOLT=%.2f\r\n", temperature, voltage);
    UART_SendString(msg);

    /* Send binary buffer (e.g., protocol frame) */
    printf("\n4. Sending binary buffer (protocol frame):\n");
    uint8_t frame[] = {0xAA, 0x01, 0x04, 0x00, 0x18, 0x55};
    /* Header=0xAA, Cmd=0x01, Len=4, Data..., Checksum=0x55 */
    UART_SendBuffer(frame, sizeof(frame));

    /* Summary */
    printf("\n--- TX Summary ---\n");
    printf("Total bytes transmitted: %d\n", tx_count);
    printf("TX buffer: ");
    int i;
    for(i = 0; i < tx_count && i < 20; i++)
        printf("0x%02X ", tx_log[i]);
    if(tx_count > 20) printf("...");
    printf("\n");

    return 0;
}
