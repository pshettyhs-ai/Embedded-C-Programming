/*
 * Program  : SPI Full Duplex Communication
 * Author   : PAVAN SHETTY H S
 * Topic    : SPI Communication
 *
 * SPI is inherently full duplex: TX and RX happen simultaneously.
 * This program shows a realistic SPI interaction with a sensor.
 *
 * Example: Reading from MPU6050-like IMU over SPI
 * Register read format:
 *   Byte 0: 0x80 | register_address  (MSB=1 means read)
 *   Byte 1: 0x00 (dummy, slave sends data here)
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated sensor register map */
#define REG_WHO_AM_I    0x75
#define REG_ACCEL_XOUT  0x3B
#define REG_TEMP_OUT    0x41
#define REG_GYRO_XOUT   0x43

/* Simulated sensor register values */
static uint8_t sensor_regs[] = {
    [0x75] = 0x68,   /* WHO_AM_I = 0x68 for MPU6050 */
    [0x3B] = 0x04,   /* ACCEL_X high byte */
    [0x3C] = 0xA0,   /* ACCEL_X low byte */
    [0x41] = 0x12,   /* TEMP high byte */
    [0x42] = 0x34,   /* TEMP low byte */
    [0x43] = 0x01,   /* GYRO_X high byte */
    [0x44] = 0x80,   /* GYRO_X low byte */
};

static int current_reg = 0;
static int read_mode   = 0;

uint8_t SPI_Transfer(uint8_t tx)
{
    uint8_t rx = 0xFF;
    if(!read_mode)
    {
        /* First byte: command byte */
        if(tx & 0x80)
        {
            read_mode   = 1;
            current_reg = tx & 0x7F;
            rx = 0xFF;
        }
    }
    else
    {
        /* Subsequent bytes: slave returns register data */
        if(current_reg < (int)sizeof(sensor_regs))
            rx = sensor_regs[current_reg];
        current_reg++;
    }
    return rx;
}

static uint8_t ss_state = 1;
void SS_Low(void)  { ss_state = 0; read_mode = 0; }
void SS_High(void) { ss_state = 1; }

uint8_t SPI_ReadReg(uint8_t reg)
{
    SS_Low();
    SPI_Transfer(0x80 | reg);  /* read command: MSB=1 */
    uint8_t val = SPI_Transfer(0x00);  /* dummy byte, get data */
    SS_High();
    return val;
}

int16_t SPI_Read16(uint8_t reg)
{
    SS_Low();
    SPI_Transfer(0x80 | reg);
    uint8_t hi = SPI_Transfer(0x00);
    uint8_t lo = SPI_Transfer(0x00);
    SS_High();
    return (int16_t)((hi << 8) | lo);
}

int main()
{
    printf("=== SPI Full Duplex - IMU Sensor Read ===\n\n");

    /* Read WHO_AM_I */
    uint8_t who = SPI_ReadReg(REG_WHO_AM_I);
    printf("WHO_AM_I register: 0x%02X (%s)\n", who,
           who == 0x68 ? "MPU6050 detected!" : "unknown device");

    /* Read accelerometer X */
    int16_t accel_x = SPI_Read16(REG_ACCEL_XOUT);
    float   accel_x_g = (float)accel_x / 16384.0f;  /* ±2g range */
    printf("Accel X raw: %d  (%.3f g)\n", accel_x, accel_x_g);

    /* Read temperature */
    int16_t temp_raw = SPI_Read16(REG_TEMP_OUT);
    float   temp_c   = (float)temp_raw / 340.0f + 36.53f;
    printf("Temp raw: %d  (%.1f C)\n", temp_raw, temp_c);

    /* Read gyroscope X */
    int16_t gyro_x = SPI_Read16(REG_GYRO_XOUT);
    float   gyro_x_dps = (float)gyro_x / 131.0f;  /* ±250 deg/s range */
    printf("Gyro X raw: %d  (%.2f deg/s)\n", gyro_x, gyro_x_dps);

    printf("\n--- SPI vs I2C vs UART ---\n");
    printf("%-10s  %-8s  %-10s  %-8s  %s\n", "Protocol", "Lines", "Speed", "Full-Dup", "Slaves");
    printf("%-10s  %-8s  %-10s  %-8s  %s\n", "SPI",  "4",    "up to 80MHz", "Yes",  "Multiple (one SS each)");
    printf("%-10s  %-8s  %-10s  %-8s  %s\n", "I2C",  "2",    "400kHz-1MHz", "No",   "Multiple (by address)");
    printf("%-10s  %-8s  %-10s  %-8s  %s\n", "UART", "2+",   "up to 1Mbps", "Yes",  "Point-to-point");

    return 0;
}
