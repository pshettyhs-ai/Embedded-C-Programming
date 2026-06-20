/*
 * Program  : SPI Master Transmit
 * Author   : PAVAN SHETTY H S
 * Topic    : SPI Communication
 *
 * SPI Transfer:
 * 1. Pull SS (CS) LOW    -> select slave
 * 2. Write byte to SPDR  -> starts clock + transfer
 * 3. Wait for SPIF flag  -> transfer complete
 * 4. Read SPDR           -> received byte (full duplex!)
 * 5. Pull SS HIGH        -> deselect slave
 *
 * Full duplex: while sending 1 byte, we receive 1 byte simultaneously!
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated SPI hardware */
static uint8_t SIM_SPDR  = 0xFF;
static uint8_t SIM_SPSR  = 0x80;  /* SPIF=1 = always ready (simulated) */
static uint8_t SIM_PORTB = 0xFF;  /* SS initially HIGH */

#define SPIF    7
#define SS_PIN  2

/* Simulated slave response buffer */
static uint8_t slave_response[] = {0x00, 0x5A, 0x3C, 0xA5, 0xFF};
static int     slave_resp_idx   = 0;

void SS_Select(void)
{
    SIM_PORTB &= ~(1 << SS_PIN);  /* SS LOW = select */
    printf("  SS LOW (slave selected)\n");
}

void SS_Deselect(void)
{
    SIM_PORTB |=  (1 << SS_PIN);  /* SS HIGH = deselect */
    printf("  SS HIGH (slave deselected)\n");
}

uint8_t SPI_Transfer(uint8_t tx_byte)
{
    /* Load TX data */
    SIM_SPDR = tx_byte;

    /* Wait for transfer complete (SPIF flag) */
    /* while(!(SIM_SPSR & (1 << SPIF))); */

    /* Simulate received byte from slave */
    uint8_t rx_byte = slave_response[slave_resp_idx % 5];
    slave_resp_idx++;

    printf("  SPI: TX=0x%02X ('%c')  RX=0x%02X ('%c')\n",
           tx_byte,  (tx_byte  >= 32 && tx_byte  < 127) ? tx_byte  : '.',
           rx_byte,  (rx_byte  >= 32 && rx_byte  < 127) ? rx_byte  : '.');
    return rx_byte;
}

/* Send only (discard received byte) */
void SPI_Send(uint8_t data)
{
    SPI_Transfer(data);
}

/* Send command + receive response */
uint8_t SPI_Command(uint8_t cmd, uint8_t arg)
{
    uint8_t resp;
    SS_Select();
    SPI_Transfer(cmd);
    resp = SPI_Transfer(arg);
    SS_Deselect();
    return resp;
}

int main()
{
    printf("=== SPI Master Transmit Demo ===\n\n");

    /* Send a single byte */
    printf("1. Single byte transfer:\n");
    SS_Select();
    SPI_Transfer(0xAB);
    SS_Deselect();

    /* Send multiple bytes (e.g., write to register) */
    printf("\n2. Write register (cmd + data):\n");
    SS_Select();
    SPI_Transfer(0x02);   /* write command */
    SPI_Transfer(0x3C);   /* register address */
    SPI_Transfer(0x5A);   /* register value */
    SS_Deselect();

    /* Example: MAX7219 LED driver */
    printf("\n3. MAX7219 LED driver (write digit 1 = '5'):\n");
    SS_Select();
    SPI_Transfer(0x01);   /* Register: Digit 0 */
    SPI_Transfer(0x6D);   /* Value: segment code for '5' */
    SS_Deselect();

    /* Example: W25Q Flash read ID */
    printf("\n4. W25Q Flash - Read Manufacturer ID:\n");
    SS_Select();
    SPI_Transfer(0x90);   /* Read Manufacturer ID command */
    SPI_Transfer(0x00);   /* dummy bytes */
    SPI_Transfer(0x00);
    SPI_Transfer(0x00);
    uint8_t mfr_id  = SPI_Transfer(0x00);  /* receive manufacturer ID */
    uint8_t dev_id  = SPI_Transfer(0x00);  /* receive device ID */
    SS_Deselect();
    printf("  Manufacturer ID: 0x%02X\n", mfr_id);
    printf("  Device ID:       0x%02X\n", dev_id);

    return 0;
}
