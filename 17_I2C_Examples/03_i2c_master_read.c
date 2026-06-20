/*
 * Program  : I2C Master Read
 * Author   : PAVAN SHETTY H S
 * Topic    : I2C Communication
 *
 * I2C Read Transaction (Register Read):
 * 1. Send START
 * 2. Send slave address + W bit (to specify register)
 * 3. Send register address
 * 4. Send REPEATED START
 * 5. Send slave address + R bit
 * 6. Read data byte(s) - send ACK for each except last
 * 7. Send NACK for last byte
 * 8. Send STOP
 *
 * Expected Output:
 * I2C read transactions from simulated sensors
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated I2C bus */
static uint8_t current_addr = 0;
static int     current_reg  = 0;

/* Simulated device register maps */
static uint8_t mpu6050_regs[256];
static uint8_t bmp280_regs[256];

void init_simulated_sensors(void)
{
    mpu6050_regs[0x75] = 0x68;  /* WHO_AM_I */
    mpu6050_regs[0x3B] = 0x02;  /* ACCEL_XOUT_H */
    mpu6050_regs[0x3C] = 0x80;  /* ACCEL_XOUT_L */
    mpu6050_regs[0x3D] = 0xFF;  /* ACCEL_YOUT_H */
    mpu6050_regs[0x3E] = 0x10;  /* ACCEL_YOUT_L */
    mpu6050_regs[0x41] = 0x11;  /* TEMP_OUT_H */
    mpu6050_regs[0x42] = 0x20;  /* TEMP_OUT_L */

    bmp280_regs[0xD0] = 0x60;   /* WHO_AM_I for BMP280 */
    bmp280_regs[0xF3] = 0x00;   /* status: not measuring */
    bmp280_regs[0xF7] = 0x51;   /* pressure MSB */
    bmp280_regs[0xF8] = 0xB4;   /* pressure LSB */
    bmp280_regs[0xF9] = 0x00;   /* pressure XLSB */
    bmp280_regs[0xFA] = 0x80;   /* temperature MSB */
    bmp280_regs[0xFB] = 0x50;   /* temperature LSB */
}

/* Low-level I2C */
void I2C_Start(void)      { printf("  START\n"); }
void I2C_RepStart(void)   { printf("  REPEATED START\n"); }
void I2C_Stop(void)       { printf("  STOP\n\n"); }

void I2C_SendAddrW(uint8_t addr)
{
    current_addr = addr;
    printf("  -> 0x%02X (addr=0x%02X, W=0) -> ACK\n", (addr<<1)|0, addr);
}

void I2C_SendAddrR(uint8_t addr)
{
    current_addr = addr;
    printf("  -> 0x%02X (addr=0x%02X, R=1) -> ACK\n", (addr<<1)|1, addr);
}

void I2C_SendByte(uint8_t data)
{
    current_reg = data;
    printf("  -> 0x%02X (reg addr) -> ACK\n", data);
}

uint8_t I2C_ReadByte_ACK(void)
{
    uint8_t data = 0xFF;
    if(current_addr == 0x68) data = mpu6050_regs[current_reg];
    if(current_addr == 0x76) data = bmp280_regs[current_reg];
    printf("  <- 0x%02X (data) -> ACK (more data coming)\n", data);
    current_reg++;
    return data;
}

uint8_t I2C_ReadByte_NACK(void)
{
    uint8_t data = 0xFF;
    if(current_addr == 0x68) data = mpu6050_regs[current_reg];
    if(current_addr == 0x76) data = bmp280_regs[current_reg];
    printf("  <- 0x%02X (data) -> NACK (last byte)\n", data);
    return data;
}

/* High-level read function */
uint8_t I2C_ReadRegister(uint8_t dev_addr, uint8_t reg_addr)
{
    I2C_Start();
    I2C_SendAddrW(dev_addr);
    I2C_SendByte(reg_addr);
    I2C_RepStart();
    I2C_SendAddrR(dev_addr);
    uint8_t data = I2C_ReadByte_NACK();
    I2C_Stop();
    return data;
}

void I2C_ReadBurst(uint8_t dev_addr, uint8_t reg_addr, uint8_t *buf, int len)
{
    I2C_Start();
    I2C_SendAddrW(dev_addr);
    I2C_SendByte(reg_addr);
    I2C_RepStart();
    I2C_SendAddrR(dev_addr);
    int i;
    for(i = 0; i < len - 1; i++)
        buf[i] = I2C_ReadByte_ACK();
    buf[len-1] = I2C_ReadByte_NACK();
    I2C_Stop();
}

int main()
{
    init_simulated_sensors();

    printf("=== I2C Master Read Demo ===\n\n");

    /* Read WHO_AM_I */
    printf("1. Read MPU6050 WHO_AM_I (register 0x75):\n");
    uint8_t who = I2C_ReadRegister(0x68, 0x75);
    printf("WHO_AM_I = 0x%02X (%s)\n\n", who,
           who == 0x68 ? "MPU6050 found!" : "unknown");

    /* Burst read accelerometer (6 bytes) */
    printf("2. Burst read accelerometer (6 bytes from 0x3B):\n");
    uint8_t accel_data[6];
    I2C_ReadBurst(0x68, 0x3B, accel_data, 6);

    int16_t ax = (int16_t)((accel_data[0] << 8) | accel_data[1]);
    int16_t ay = (int16_t)((accel_data[2] << 8) | accel_data[3]);
    printf("Accel X = %d (%.3f g)\n", ax, ax / 16384.0f);
    printf("Accel Y = %d (%.3f g)\n\n", ay, ay / 16384.0f);

    /* Read BMP280 temperature */
    printf("3. Read BMP280 temperature (0xFA-0xFB):\n");
    uint8_t temp_data[2];
    I2C_ReadBurst(0x76, 0xFA, temp_data, 2);
    int32_t raw_temp = ((int32_t)temp_data[0] << 12) | ((int32_t)temp_data[1] << 4);
    printf("Raw temp = %d\n", raw_temp);

    return 0;
}
