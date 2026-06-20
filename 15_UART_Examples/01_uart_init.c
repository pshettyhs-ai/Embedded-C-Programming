/*
 * Program  : UART Initialization
 * Author   : PAVAN SHETTY H S
 * Topic    : UART Communication
 * Target   : STM32F103 / AVR ATmega328P (register-level concept)
 *
 * UART = Universal Asynchronous Receiver Transmitter
 * Most common serial protocol in embedded systems.
 * Used for: debug prints, GPS, Bluetooth (HC-05), GSM modules.
 *
 * Key settings:
 * - Baud Rate  : speed in bits/second (9600, 115200 common)
 * - Data bits  : usually 8
 * - Stop bits  : usually 1
 * - Parity     : usually None
 * "8N1" = 8 data bits, No parity, 1 stop bit (most common!)
 *
 * Baud Rate Calculation (AVR):
 * UBRR = (F_CPU / (16 * BAUD)) - 1
 *
 * Expected Output:
 * UART initialization steps and register values
 */

#include <stdio.h>
#include <stdint.h>

/* ===== Simulated UART Registers (AVR style) ===== */
static uint8_t  SIM_UCSR0A = 0x00;  /* UART Control Status Register A */
static uint8_t  SIM_UCSR0B = 0x00;  /* UART Control Status Register B */
static uint8_t  SIM_UCSR0C = 0x00;  /* UART Control Status Register C */
static uint16_t SIM_UBRR0  = 0;     /* UART Baud Rate Register */
static uint8_t  SIM_UDR0   = 0;     /* UART Data Register */

/* UCSR0A bits */
#define UDRE0   5   /* USART Data Register Empty */
#define RXC0    7   /* USART Receive Complete */
#define TXC0    6   /* USART Transmit Complete */

/* UCSR0B bits */
#define RXEN0   4   /* Receiver Enable */
#define TXEN0   3   /* Transmitter Enable */
#define RXCIE0  7   /* RX Complete Interrupt Enable */

/* UCSR0C bits */
#define UCSZ01  2   /* Character Size bit 1 */
#define UCSZ00  1   /* Character Size bit 0 */

#define F_CPU       16000000UL  /* 16 MHz */

/* Calculate UBRR value from baud rate */
#define UBRR_VALUE(baud)   ((F_CPU / (16UL * (baud))) - 1)

void UART_Init(uint32_t baud_rate)
{
    printf("--- UART Initialization ---\n");
    printf("F_CPU     = %lu Hz\n", F_CPU);
    printf("Baud Rate = %lu\n", baud_rate);

    /* Step 1: Set baud rate */
    uint16_t ubrr = (uint16_t)UBRR_VALUE(baud_rate);
    SIM_UBRR0 = ubrr;
    printf("\nStep 1: Set Baud Rate\n");
    printf("  UBRR = (F_CPU / (16 * BAUD)) - 1\n");
    printf("       = (%lu / (16 * %lu)) - 1\n", F_CPU, baud_rate);
    printf("       = %u\n", ubrr);
    printf("  UBRR0 = %u (0x%04X)\n", SIM_UBRR0, SIM_UBRR0);

    /* Actual baud rate with this UBRR */
    float actual_baud = (float)F_CPU / (16.0f * (ubrr + 1));
    float error_pct   = ((actual_baud - baud_rate) / baud_rate) * 100.0f;
    printf("  Actual baud: %.1f (error: %.2f%%)\n", actual_baud, error_pct);

    /* Step 2: Enable TX and RX */
    SIM_UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    printf("\nStep 2: Enable TX and RX\n");
    printf("  UCSR0B = 0x%02X (TXEN=1, RXEN=1)\n", SIM_UCSR0B);

    /* Step 3: Set frame format: 8 data bits, 1 stop bit, no parity */
    SIM_UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  /* 8-bit data */
    printf("\nStep 3: Set Frame Format (8N1)\n");
    printf("  UCSR0C = 0x%02X (8 data bits, no parity, 1 stop bit)\n", SIM_UCSR0C);

    printf("\nUART initialized successfully!\n");
    printf("Settings: %lu 8N1\n\n", baud_rate);
}

int main()
{
    printf("=== UART Init Demo (AVR ATmega328P) ===\n\n");

    /* Common baud rates */
    uint32_t baud_rates[] = {9600, 38400, 115200};
    int i;
    for(i = 0; i < 3; i++)
    {
        UART_Init(baud_rates[i]);
    }

    printf("--- Common UART Baud Rates ---\n");
    printf("%-8s  %-8s  %s\n", "Baud", "UBRR", "Use Case");
    printf("%-8s  %-8s  %s\n", "----", "----", "--------");
    uint32_t bauds[] = {1200, 2400, 9600, 19200, 38400, 57600, 115200};
    int nb = 7;
    for(i = 0; i < nb; i++)
    {
        uint16_t ubrr = (uint16_t)UBRR_VALUE(bauds[i]);
        printf("%-8lu  %-8u  ", bauds[i], ubrr);
        if(bauds[i] == 9600)        printf("GPS, Bluetooth HC-05\n");
        else if(bauds[i] == 115200) printf("Debug console, high-speed\n");
        else if(bauds[i] == 38400)  printf("Older GSM modules\n");
        else                         printf("General use\n");
    }

    return 0;
}
