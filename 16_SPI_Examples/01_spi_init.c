/*
 * Program  : SPI Initialization
 * Author   : PAVAN SHETTY H S
 * Topic    : SPI Communication
 * Target   : AVR ATmega328P (register-level)
 *
 * SPI = Serial Peripheral Interface
 * A synchronous, full-duplex serial protocol.
 * Faster than UART and I2C.
 *
 * Signals:
 * MOSI = Master Out Slave In  (master sends)
 * MISO = Master In Slave Out  (slave sends)
 * SCK  = Serial Clock         (master generates)
 * SS   = Slave Select (CS)    (active LOW, selects which slave)
 *
 * Modes (CPOL + CPHA):
 * Mode 0 (CPOL=0, CPHA=0) - most common
 * Mode 1 (CPOL=0, CPHA=1)
 * Mode 2 (CPOL=1, CPHA=0)
 * Mode 3 (CPOL=1, CPHA=1)
 *
 * AVR SPI pins (ATmega328P):
 * MOSI = PB3 (pin 11)
 * MISO = PB4 (pin 12)
 * SCK  = PB5 (pin 13)
 * SS   = PB2 (pin 10)
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated SPI registers (AVR) */
static uint8_t SIM_DDRB  = 0x00;
static uint8_t SIM_SPCR  = 0x00;  /* SPI Control Register */
static uint8_t SIM_SPSR  = 0x00;  /* SPI Status Register */
static uint8_t SIM_SPDR  = 0x00;  /* SPI Data Register */

/* SPCR bits */
#define SPIE  7   /* SPI Interrupt Enable */
#define SPE   6   /* SPI Enable */
#define DORD  5   /* Data Order (0=MSB first) */
#define MSTR  4   /* Master/Slave Select (1=master) */
#define CPOL  3   /* Clock Polarity */
#define CPHA  2   /* Clock Phase */
#define SPR1  1   /* SPI Clock Rate bit 1 */
#define SPR0  0   /* SPI Clock Rate bit 0 */

/* SPSR bits */
#define SPIF  7   /* SPI Interrupt Flag (1=transfer complete) */
#define SPI2X 0   /* Double SPI Speed */

/* Pin definitions */
#define SS_PIN   2
#define MOSI_PIN 3
#define MISO_PIN 4
#define SCK_PIN  5

void SPI_MasterInit(void)
{
    printf("--- SPI Master Initialization ---\n");

    /* Step 1: Set MOSI, SCK, SS as output; MISO as input */
    SIM_DDRB |=  (1 << MOSI_PIN) | (1 << SCK_PIN) | (1 << SS_PIN);
    SIM_DDRB &= ~(1 << MISO_PIN);
    printf("Step 1: Pin directions set\n");
    printf("  DDRB = 0x%02X (MOSI/SCK/SS=out, MISO=in)\n", SIM_DDRB);

    /* Step 2: Deselect slave (SS HIGH) */
    /* SIM_PORTB |= (1 << SS_PIN); */
    printf("Step 2: SS set HIGH (slave deselected)\n");

    /* Step 3: Configure SPI Control Register */
    /* SPE=1 (enable), MSTR=1 (master), CPOL=0, CPHA=0, SPR0=1 (clock = F_CPU/16) */
    SIM_SPCR = (1 << SPE) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (1 << SPR0);
    printf("Step 3: SPI Control Register configured\n");
    printf("  SPCR = 0x%02X\n", SIM_SPCR);
    printf("  SPE=1 (enabled), MSTR=1 (master), CPOL=0, CPHA=0\n");
    printf("  Clock = F_CPU/16 = 1 MHz (at 16 MHz CPU)\n");

    printf("\nSPI Master initialized! Mode 0, 1 MHz\n\n");
}

int main()
{
    printf("=== SPI Initialization Demo ===\n\n");

    SPI_MasterInit();

    /* SPI Clock rates */
    printf("--- SPI Clock Rates (F_CPU = 16MHz) ---\n");
    printf("SPI2X=0, SPR1=0, SPR0=0 -> F_CPU/4   =  4.0 MHz\n");
    printf("SPI2X=0, SPR1=0, SPR0=1 -> F_CPU/16  =  1.0 MHz\n");
    printf("SPI2X=0, SPR1=1, SPR0=0 -> F_CPU/64  =  250 kHz\n");
    printf("SPI2X=0, SPR1=1, SPR0=1 -> F_CPU/128 =  125 kHz\n");
    printf("SPI2X=1, SPR1=0, SPR0=0 -> F_CPU/2   =  8.0 MHz (fastest!)\n");

    printf("\n--- SPI Modes ---\n");
    printf("Mode 0: CPOL=0, CPHA=0 -> Clock idle LOW,  sample on rising  edge\n");
    printf("Mode 1: CPOL=0, CPHA=1 -> Clock idle LOW,  sample on falling edge\n");
    printf("Mode 2: CPOL=1, CPHA=0 -> Clock idle HIGH, sample on falling edge\n");
    printf("Mode 3: CPOL=1, CPHA=1 -> Clock idle HIGH, sample on rising  edge\n");

    printf("\n--- Common SPI Devices ---\n");
    printf("SD Card         : Mode 0, up to 25 MHz\n");
    printf("W25Q Flash chip : Mode 0 or 3, up to 80 MHz\n");
    printf("MAX7219 LED driver: Mode 0\n");
    printf("MPU6050 IMU     : Mode 3 (also has I2C)\n");
    printf("NRF24L01 radio  : Mode 0, 10 MHz\n");

    return 0;
}
