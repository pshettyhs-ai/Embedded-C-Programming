/*
 * Program  : SPI Slave Receive (Conceptual)
 * Author   : PAVAN SHETTY H S
 * Topic    : SPI Communication
 *
 * In a slave device:
 * - SS going LOW wakes up the slave
 * - Slave reads bytes shifted in on MOSI
 * - Slave simultaneously sends data on MISO
 * - Process data when SS goes HIGH again
 *
 * AVR can also operate in SPI slave mode.
 * This shows how you'd configure and use it.
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated slave registers */
static uint8_t SIM_SPCR = 0x00;
static uint8_t SIM_DDRB = 0x00;

#define SPE   6
#define MSTR  4
#define SPIF  7

/* Slave internal state */
static uint8_t  slave_rx_buf[16];
static uint8_t  slave_rx_idx = 0;
static uint8_t  slave_tx_buf[] = {0xAA, 0xBB, 0xCC, 0xDD};
static uint8_t  slave_tx_idx = 0;
static volatile uint8_t ss_active = 0;

void SPI_SlaveInit(void)
{
    printf("--- SPI Slave Initialization ---\n");

    /* MISO = output, others = input */
    SIM_DDRB |=  (1 << 4);   /* MISO = output */
    SIM_DDRB &= ~((1<<2)|(1<<3)|(1<<5)); /* SS, MOSI, SCK = input */
    printf("DDRB = 0x%02X (MISO=out, others=in)\n", SIM_DDRB);

    /* Enable SPI, slave mode (MSTR=0) */
    SIM_SPCR = (1 << SPE);   /* enable SPI, slave (MSTR=0) */
    printf("SPCR = 0x%02X (SPE=1, MSTR=0 = slave mode)\n\n", SIM_SPCR);
}

/* Simulate receiving a byte as slave */
uint8_t SPI_SlaveTransfer(uint8_t tx_byte)
{
    /* Pre-load TX byte into SPDR (this goes out during next transfer) */
    /* SPDR = tx_byte; */

    /* Wait for transfer complete */
    /* while(!(SPSR & (1 << SPIF))); */

    /* Read received byte */
    /* return SPDR; */

    printf("  [SLAVE] TX=0x%02X, ", tx_byte);
    slave_tx_idx = (slave_tx_idx + 1) % 4;
    return 0x42;  /* simulated received data */
}

/* SS change handlers (usually external interrupt) */
void SS_Falling_Edge(void)   /* SS went LOW = new transaction starting */
{
    ss_active = 1;
    slave_rx_idx = 0;
    slave_tx_idx = 0;
    printf("  [SLAVE] SS LOW - transaction start\n");
}

void SS_Rising_Edge(void)    /* SS went HIGH = transaction done */
{
    ss_active = 0;
    printf("  [SLAVE] SS HIGH - transaction end (%d bytes received)\n", slave_rx_idx);
    /* Process slave_rx_buf here */
}

int main()
{
    printf("=== SPI Slave Mode Demo ===\n\n");

    SPI_SlaveInit();

    printf("Simulating a master sending 3 bytes to slave:\n\n");

    /* Simulate a transaction */
    SS_Falling_Edge();
    uint8_t bytes[] = {0x02, 0x10, 0xAB};
    int i;
    for(i = 0; i < 3; i++)
    {
        slave_rx_buf[slave_rx_idx] = bytes[i];
        printf("  [SLAVE] Received byte %d: 0x%02X\n", i+1, slave_rx_buf[slave_rx_idx]);
        slave_rx_idx++;
    }
    SS_Rising_Edge();

    printf("\nSlave received data: ");
    for(i = 0; i < slave_rx_idx; i++)
        printf("0x%02X ", slave_rx_buf[i]);
    printf("\n");

    printf("\nNote: In real SPI slave, you use SPIF interrupt or poll for each byte.\n");
    printf("ISR(SPI_STC_vect) { rx_buf[idx++] = SPDR; SPDR = tx_buf[idx]; }\n");

    return 0;
}
