/*
 * Program  : I2C Master Write
 * Author   : PAVAN SHETTY H S
 * Topic    : I2C Communication
 *
 * I2C Write Transaction:
 * 1. Send START condition
 * 2. Send slave address + W bit (address << 1 | 0)
 * 3. Wait for ACK from slave
 * 4. Send register address
 * 5. Send data byte(s)
 * 6. Send STOP condition
 *
 * Expected Output:
 * I2C write transactions to simulated devices
 */

#include <stdio.h>
#include <stdint.h>

/* Status codes */
#define I2C_OK    0
#define I2C_ERR  -1

/* Simulated I2C bus state */
static uint8_t  bus_sda      = 1;
static uint8_t  bus_scl      = 1;
static uint8_t  current_addr = 0;
static uint8_t  ack_return   = 1;  /* 1 = ACK, 0 = NACK */

static uint8_t  i2c_reg_map[256][256];  /* [device_addr][reg] = value */
static int      i2c_current_reg = 0;

void print_bus(const char *op, uint8_t data)
{
    printf("  [I2C] %-12s | 0x%02X\n", op, data);
}

/* ===== I2C Low-Level Functions ===== */
int I2C_Start(void)
{
    print_bus("START", 0);
    return I2C_OK;
}

int I2C_Stop(void)
{
    print_bus("STOP", 0);
    return I2C_OK;
}

int I2C_WriteByte(uint8_t data)
{
    i2c_reg_map[current_addr][i2c_current_reg] = data;
    print_bus("WRITE", data);
    printf("          ACK <- slave 0x%02X\n", current_addr);
    return I2C_OK;
}

int I2C_SendAddr_W(uint8_t addr)
{
    current_addr = addr;
    uint8_t addr_byte = (addr << 1) | 0;  /* address + write bit */
    print_bus("ADDR+W", addr_byte);
    printf("          ACK <- slave 0x%02X\n", addr);
    return I2C_OK;
}

/* ===== High-Level Write Function ===== */
int I2C_WriteRegister(uint8_t dev_addr, uint8_t reg_addr, uint8_t data)
{
    int ret;
    ret = I2C_Start();
    if(ret != I2C_OK) return ret;

    ret = I2C_SendAddr_W(dev_addr);
    if(ret != I2C_OK) { I2C_Stop(); return ret; }

    i2c_current_reg = reg_addr;
    ret = I2C_WriteByte(reg_addr);
    if(ret != I2C_OK) { I2C_Stop(); return ret; }

    ret = I2C_WriteByte(data);
    I2C_Stop();
    return ret;
}

int main()
{
    printf("=== I2C Master Write Demo ===\n\n");

    /* Example 1: Configure MPU6050 IMU */
    printf("1. MPU6050 - Wake up (write PWR_MGMT_1):\n");
    I2C_WriteRegister(0x68, 0x6B, 0x00);  /* clear sleep bit */

    printf("\n2. MPU6050 - Set accelerometer range ±2g:\n");
    I2C_WriteRegister(0x68, 0x1C, 0x00);

    printf("\n3. MPU6050 - Set gyro range ±250 deg/s:\n");
    I2C_WriteRegister(0x68, 0x1B, 0x00);

    /* Example 2: SSD1306 OLED display command */
    printf("\n4. SSD1306 OLED - Set display ON:\n");
    I2C_WriteRegister(0x3C, 0x00, 0xAF);  /* command byte 0x00, data 0xAF = ON */

    /* Example 3: PCF8574 GPIO expander */
    printf("\n5. PCF8574 - Set all output pins HIGH:\n");
    if(I2C_Start() == I2C_OK)
    {
        I2C_SendAddr_W(0x20);
        I2C_WriteByte(0xFF);  /* PCF8574: just write data, no register needed */
        I2C_Stop();
    }

    printf("\n--- I2C Write Transaction Format ---\n");
    printf("START -> [ADDR+W] -> ACK -> [REG] -> ACK -> [DATA] -> ACK -> STOP\n");
    printf("                                                              ^\n");
    printf("                                    Repeat for multiple bytes-+\n");

    return 0;
}
