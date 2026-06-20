# 16 - SPI Examples

SPI is the fastest standard serial protocol.
Used for: SD cards, Flash memory, displays, sensors (IMU, ADC), radio modules.

## Files

| File | Topic |
|------|-------|
| 01_spi_init.c | SPI init, clock rates, modes |
| 02_spi_master_transmit.c | Sending bytes, SS control |
| 03_spi_slave_receive.c | Slave mode configuration |
| 04_spi_full_duplex.c | Full duplex IMU sensor read |

## Quick Reference

```c
void SPI_Transfer(uint8_t data) {
    SPDR = data;                       // load data
    while(!(SPSR & (1 << SPIF)));      // wait for complete
}
```

## SPI Signals
- **MOSI** = Master Out Slave In
- **MISO** = Master In Slave Out
- **SCK**  = Serial Clock (master generates)
- **SS/CS** = Slave Select (active LOW)

## Interview Notes
- SPI is **synchronous** (has clock line) unlike UART
- Full-duplex: TX and RX happen at the same time
- One SS line needed per slave
- 4 modes based on CPOL and CPHA settings
