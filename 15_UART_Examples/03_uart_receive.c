/*
 * Program  : UART Receive - Read Data
 * Author   : PAVAN SHETTY H S
 * Topic    : UART Communication
 *
 * Two methods to receive UART data:
 * 1. Polling  - keep checking RXC flag in main loop (simple but wastes CPU)
 * 2. Interrupt - ISR is called automatically when byte arrives (better!)
 *
 * Expected Output:
 * Simulated UART receive with ring buffer
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Simulated registers */
static uint8_t SIM_UCSR0A = 0x00;
static uint8_t SIM_UDR0   = 0;

#define RXC0   7   /* RX Complete flag - set when data is ready */

/* ===== Ring Buffer for UART RX ===== */
#define RX_BUF_SIZE  64

static volatile uint8_t rx_buffer[RX_BUF_SIZE];
static volatile uint8_t rx_head  = 0;  /* write index (ISR writes here) */
static volatile uint8_t rx_tail  = 0;  /* read  index (main reads here) */
static volatile uint8_t rx_count = 0;

/* Put byte into ring buffer (called from ISR) */
void rx_buffer_put(uint8_t data)
{
    if(rx_count < RX_BUF_SIZE)
    {
        rx_buffer[rx_head] = data;
        rx_head = (rx_head + 1) % RX_BUF_SIZE;
        rx_count++;
    }
    /* else: buffer full, byte dropped */
}

/* Get byte from ring buffer (called from main) */
int rx_buffer_get(uint8_t *data)
{
    if(rx_count == 0) return 0;  /* buffer empty */

    *data   = rx_buffer[rx_tail];
    rx_tail = (rx_tail + 1) % RX_BUF_SIZE;
    rx_count--;
    return 1;
}

/* Simulated UART RX ISR */
void USART0_RX_vect(uint8_t received_byte)
{
    /* In real AVR: ISR(USART_RX_vect) { rx_buffer_put(UDR0); } */
    rx_buffer_put(received_byte);
}

/* Polling receive (simple, blocking) */
uint8_t UART_ReceiveByte_Polling(void)
{
    /* Wait for data - blocks until byte arrives */
    while(!(SIM_UCSR0A & (1 << RXC0)));
    return SIM_UDR0;
}

int main()
{
    printf("=== UART Receive Demo ===\n\n");

    /* Simulate receiving bytes via ISR */
    printf("1. Simulating ISR-based reception:\n");
    const char *incoming = "Hello MCU\r\n";
    int i;
    for(i = 0; incoming[i]; i++)
    {
        USART0_RX_vect((uint8_t)incoming[i]);
    }
    printf("   ISR received %d bytes, buffer count = %d\n",
           (int)strlen(incoming), rx_count);

    /* Main loop reads from buffer */
    printf("\n2. Main loop reading from ring buffer:\n");
    printf("   Received: \"");
    uint8_t byte;
    while(rx_buffer_get(&byte))
    {
        if(byte != '\r' && byte != '\n')
            printf("%c", byte);
    }
    printf("\"\n");
    printf("   Buffer count after read = %d\n", rx_count);

    /* Receive a full line */
    printf("\n3. Receive until newline (command parsing):\n");
    const char *cmd = "AT+BAUD=115200\r\n";
    for(i = 0; cmd[i]; i++)
        USART0_RX_vect((uint8_t)cmd[i]);

    char line_buf[64];
    int  line_len = 0;
    while(rx_buffer_get(&byte))
    {
        if(byte == '\r' || byte == '\n') break;
        line_buf[line_len++] = (char)byte;
    }
    line_buf[line_len] = '\0';
    printf("   Command received: \"%s\"\n", line_buf);
    printf("   Parsing: command=AT+BAUD, value=%s\n",
           strchr(line_buf, '=') ? strchr(line_buf, '=') + 1 : "none");

    printf("\n--- Ring Buffer Summary ---\n");
    printf("Buffer size : %d bytes\n", RX_BUF_SIZE);
    printf("Benefits    : Non-blocking, no data loss if main is busy\n");
    printf("ISR         : Just writes to buffer (fast!)\n");
    printf("Main loop   : Reads from buffer when ready\n");

    return 0;
}
