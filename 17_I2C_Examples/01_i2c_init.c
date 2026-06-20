/*
 * Program  : I2C Initialization
 * Author   : PAVAN SHETTY H S
 * Topic    : I2C Communication
 * Target   : AVR ATmega328P (TWI = Two Wire Interface)
 *
 * I2C = Inter-Integrated Circuit (also called TWI on AVR)
 * Uses only 2 wires: SDA (data) and SCL (clock)
 * Can have multiple devices on same 2 wires using addresses!
 *
 * Signals:
 * SDA = Serial Data
 * SCL = Serial Clock
 *
 * Both lines need pull-up resistors (typically 4.7kΩ)
 *
 * Speeds:
 * Standard mode : 100 kHz
 * Fast mode     : 400 kHz
 * Fast-Plus     : 1 MHz
 *
 * Address: 7-bit (0x00-0x7F) or 10-bit
 * First byte = address (7 bits) + R/W bit (1 bit)
 *
 * AVR TWI pins:
 * SDA = PC4 (A4 on Arduino)
 * SCL = PC5 (A5 on Arduino)
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated TWI (I2C) registers */
static uint8_t SIM_TWBR  = 0;     /* TWI Bit Rate Register */
static uint8_t SIM_TWCR  = 0;     /* TWI Control Register */
static uint8_t SIM_TWSR  = 0xF8;  /* TWI Status Register (prescaler bits = 0) */
static uint8_t SIM_TWDR  = 0;     /* TWI Data Register */
static uint8_t SIM_TWAR  = 0;     /* TWI Address Register (slave mode) */

/* TWCR bits */
#define TWINT  7   /* TWI Interrupt Flag */
#define TWEA   6   /* TWI Enable Acknowledge */
#define TWSTA  5   /* TWI START Condition */
#define TWSTO  4   /* TWI STOP Condition */
#define TWWC   3   /* TWI Write Collision Flag */
#define TWEN   2   /* TWI Enable */
#define TWIE   0   /* TWI Interrupt Enable */

/* TWI Status Codes */
#define TW_START         0x08
#define TW_REP_START     0x10
#define TW_MT_SLA_ACK    0x18  /* Master TX: SLA+W sent, ACK received */
#define TW_MT_DATA_ACK   0x28  /* Master TX: Data sent, ACK received */
#define TW_MR_SLA_ACK    0x40  /* Master RX: SLA+R sent, ACK received */
#define TW_MR_DATA_ACK   0x58  /* Master RX: Data received, ACK sent */

#define F_CPU    16000000UL
#define F_SCL    100000UL       /* 100 kHz I2C */

void I2C_Init(uint32_t scl_freq)
{
    printf("--- I2C (TWI) Initialization ---\n");
    printf("F_CPU   = %lu Hz\n", F_CPU);
    printf("SCL Freq= %lu Hz\n", scl_freq);

    /* Step 1: Set prescaler to 1 (TWPS1:0 = 00) */
    SIM_TWSR &= ~0x03;   /* clear prescaler bits */
    printf("\nStep 1: Prescaler = 1 (TWSR bits [1:0] = 00)\n");

    /* Step 2: Set bit rate register */
    /* TWBR = (F_CPU/SCL - 16) / (2 * prescaler) */
    uint8_t twbr = (uint8_t)((F_CPU / scl_freq - 16) / (2 * 1));
    SIM_TWBR = twbr;
    printf("Step 2: TWBR = (F_CPU/SCL - 16) / 2\n");
    printf("             = (%lu/%lu - 16) / 2\n", F_CPU, scl_freq);
    printf("             = %u\n", twbr);
    printf("  TWBR = %u\n", SIM_TWBR);

    /* Step 3: Enable TWI */
    SIM_TWCR = (1 << TWEN);
    printf("Step 3: TWI enabled. TWCR = 0x%02X\n", SIM_TWCR);

    /* Verify actual SCL */
    float actual_scl = (float)F_CPU / (16.0f + 2.0f * twbr);
    printf("\nActual SCL: %.1f kHz\n", actual_scl / 1000.0f);
    printf("I2C ready!\n\n");
}

int main()
{
    printf("=== I2C Initialization Demo ===\n\n");

    /* Standard mode: 100kHz */
    I2C_Init(100000);

    /* Fast mode: 400kHz */
    printf("--- Fast Mode (400 kHz) ---\n");
    uint8_t twbr_fast = (uint8_t)((F_CPU / 400000UL - 16) / 2);
    printf("TWBR for 400kHz = %u\n\n", twbr_fast);

    /* Common I2C device addresses */
    printf("--- Common I2C Device Addresses ---\n");
    printf("%-20s  %-10s  %s\n", "Device", "Address", "Notes");
    printf("%-20s  %-10s  %s\n", "------", "-------", "-----");
    printf("%-20s  %-10s  %s\n", "MPU6050 IMU",    "0x68 / 0x69", "AD0 pin selects");
    printf("%-20s  %-10s  %s\n", "BMP280 pressure","0x76 / 0x77", "SDO pin selects");
    printf("%-20s  %-10s  %s\n", "SSD1306 OLED",   "0x3C / 0x3D", "SA0 pin selects");
    printf("%-20s  %-10s  %s\n", "PCF8574 I/O exp","0x20-0x27",   "A0-A2 pins");
    printf("%-20s  %-10s  %s\n", "DS3231 RTC",     "0x68",        "fixed");
    printf("%-20s  %-10s  %s\n", "AT24C EEPROM",   "0x50-0x57",   "A0-A2 pins");
    printf("%-20s  %-10s  %s\n", "ADS1115 ADC",    "0x48-0x4B",   "ADDR pin");

    return 0;
}
