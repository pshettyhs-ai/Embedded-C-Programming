/*
 * Program  : Reading a Real Sensor over I2C - MPU6050
 * Author   : PAVAN SHETTY H S
 * Topic    : I2C Communication
 *
 * Complete example of reading MPU6050 6-axis IMU sensor.
 * Covers: init, calibration offset, reading and converting data.
 *
 * MPU6050 I2C Address: 0x68 (AD0=0) or 0x69 (AD0=1)
 *
 * Registers used:
 * 0x6B = PWR_MGMT_1  (wake up sensor)
 * 0x1B = GYRO_CONFIG  (set range)
 * 0x1C = ACCEL_CONFIG (set range)
 * 0x3B = ACCEL_XOUT_H (start of data registers, 14 bytes)
 */

#include <stdio.h>
#include <stdint.h>

#define MPU6050_ADDR    0x68

/* MPU6050 Registers */
#define MPU_PWR_MGMT_1  0x6B
#define MPU_GYRO_CONFIG 0x1B
#define MPU_ACCEL_CONFIG 0x1C
#define MPU_ACCEL_XOUT_H 0x3B
#define MPU_WHO_AM_I    0x75

/* Sensitivity values */
#define ACCEL_SENS_2G   16384.0f   /* LSB/g  for ±2g range */
#define GYRO_SENS_250   131.0f     /* LSB/dps for ±250 dps range */
#define TEMP_SENS       340.0f
#define TEMP_OFFSET     36.53f

/* Simulated register bank for MPU6050 */
static uint8_t mpu_regs[256] = {
    [0x75] = 0x68,  /* WHO_AM_I */
    [0x6B] = 0x40,  /* PWR_MGMT_1: sleep mode by default */
    [0x3B] = 0x01,  /* ACCEL_XOUT_H */
    [0x3C] = 0xA0,  /* ACCEL_XOUT_L */
    [0x3D] = 0xFF,  /* ACCEL_YOUT_H */
    [0x3E] = 0x00,  /* ACCEL_YOUT_L */
    [0x3F] = 0x40,  /* ACCEL_ZOUT_H  (approx 1g = 0x4000) */
    [0x40] = 0x00,  /* ACCEL_ZOUT_L */
    [0x41] = 0x12,  /* TEMP_OUT_H */
    [0x42] = 0x34,  /* TEMP_OUT_L */
    [0x43] = 0x00,  /* GYRO_XOUT_H */
    [0x44] = 0x50,  /* GYRO_XOUT_L */
    [0x45] = 0x00,  /* GYRO_YOUT_H */
    [0x46] = 0x20,  /* GYRO_YOUT_L */
    [0x47] = 0x00,  /* GYRO_ZOUT_H */
    [0x48] = 0x00,  /* GYRO_ZOUT_L */
};

/* Simulated I2C read/write */
void I2C_WriteReg(uint8_t addr, uint8_t reg, uint8_t val)
{
    (void)addr;
    mpu_regs[reg] = val;
}

uint8_t I2C_ReadReg(uint8_t addr, uint8_t reg)
{
    (void)addr;
    return mpu_regs[reg];
}

void I2C_ReadBurst(uint8_t addr, uint8_t reg, uint8_t *buf, int len)
{
    int i;
    (void)addr;
    for(i = 0; i < len; i++)
        buf[i] = mpu_regs[reg + i];
}

/* ===== MPU6050 Driver Functions ===== */

int MPU6050_Init(void)
{
    /* Check WHO_AM_I */
    uint8_t id = I2C_ReadReg(MPU6050_ADDR, MPU_WHO_AM_I);
    if(id != 0x68)
    {
        printf("MPU6050 not found! ID=0x%02X\n", id);
        return -1;
    }
    printf("MPU6050 found! ID=0x%02X\n", id);

    /* Wake up (clear sleep bit in PWR_MGMT_1) */
    I2C_WriteReg(MPU6050_ADDR, MPU_PWR_MGMT_1, 0x00);
    printf("MPU6050 woken up\n");

    /* Set accelerometer: ±2g range */
    I2C_WriteReg(MPU6050_ADDR, MPU_ACCEL_CONFIG, 0x00);
    printf("Accel range: ±2g\n");

    /* Set gyroscope: ±250 dps range */
    I2C_WriteReg(MPU6050_ADDR, MPU_GYRO_CONFIG, 0x00);
    printf("Gyro range: ±250 dps\n\n");

    return 0;
}

typedef struct {
    float ax, ay, az;   /* acceleration in g */
    float gx, gy, gz;   /* angular velocity in dps */
    float temp_c;        /* temperature in Celsius */
} MPU6050_Data;

void MPU6050_Read(MPU6050_Data *data)
{
    uint8_t raw[14];
    I2C_ReadBurst(MPU6050_ADDR, MPU_ACCEL_XOUT_H, raw, 14);

    int16_t ax_raw = (int16_t)((raw[0]  << 8) | raw[1]);
    int16_t ay_raw = (int16_t)((raw[2]  << 8) | raw[3]);
    int16_t az_raw = (int16_t)((raw[4]  << 8) | raw[5]);
    int16_t t_raw  = (int16_t)((raw[6]  << 8) | raw[7]);
    int16_t gx_raw = (int16_t)((raw[8]  << 8) | raw[9]);
    int16_t gy_raw = (int16_t)((raw[10] << 8) | raw[11]);
    int16_t gz_raw = (int16_t)((raw[12] << 8) | raw[13]);

    data->ax     = ax_raw / ACCEL_SENS_2G;
    data->ay     = ay_raw / ACCEL_SENS_2G;
    data->az     = az_raw / ACCEL_SENS_2G;
    data->gx     = gx_raw / GYRO_SENS_250;
    data->gy     = gy_raw / GYRO_SENS_250;
    data->gz     = gz_raw / GYRO_SENS_250;
    data->temp_c = (float)t_raw / TEMP_SENS + TEMP_OFFSET;
}

int main()
{
    printf("=== MPU6050 I2C Sensor Read ===\n\n");

    if(MPU6050_Init() != 0)
        return 1;

    MPU6050_Data sensor;
    MPU6050_Read(&sensor);

    printf("=== Sensor Readings ===\n");
    printf("Accelerometer:\n");
    printf("  X = %+.3f g\n", sensor.ax);
    printf("  Y = %+.3f g\n", sensor.ay);
    printf("  Z = %+.3f g  (should be ~1.0g when flat)\n", sensor.az);

    printf("Gyroscope:\n");
    printf("  X = %+.2f dps\n", sensor.gx);
    printf("  Y = %+.2f dps\n", sensor.gy);
    printf("  Z = %+.2f dps\n", sensor.gz);

    printf("Temperature: %.1f C\n", sensor.temp_c);

    printf("\nNote: In real firmware, call MPU6050_Read() every ~10ms\n");
    printf("and feed data into a Kalman/Complementary filter for orientation.\n");

    return 0;
}
