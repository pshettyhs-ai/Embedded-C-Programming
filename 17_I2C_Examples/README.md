# 17 - I2C Examples

I2C uses only 2 wires but supports many devices on the same bus.
Very popular for sensors, EEPROMs, RTCs, displays.

## Files

| File | Topic |
|------|-------|
| 01_i2c_init.c | Init, baud rate, device addresses |
| 02_i2c_master_write.c | Write to register (MPU6050, OLED) |
| 03_i2c_master_read.c | Single and burst read |
| 04_i2c_sensor_read.c | Full MPU6050 driver |

## I2C Transaction Format

**Write:**
```
START -> [ADDR+W] -> ACK -> [REG] -> ACK -> [DATA] -> ACK -> STOP
```

**Read:**
```
START -> [ADDR+W] -> ACK -> [REG] -> ACK ->
REPEATED START -> [ADDR+R] -> ACK -> [DATA] -> NACK -> STOP
```

## Interview Notes
- I2C is **synchronous** (has clock) and **half-duplex** (SDA shared)
- 7-bit address → 128 devices possible (some reserved)
- Pull-up resistors (4.7kΩ) needed on SDA and SCL
- ACK = slave pulls SDA LOW, NACK = SDA stays HIGH
- **Repeated START** used between write and read without releasing bus
- Standard: 100kHz, Fast: 400kHz, Fast-Plus: 1MHz
