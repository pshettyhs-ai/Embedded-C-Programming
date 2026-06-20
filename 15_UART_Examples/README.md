# 15 - UART Examples

UART is the most widely used serial protocol.
First thing to get working on any new MCU board — it gives you printf debugging!

## Files

| File | Topic |
|------|-------|
| 01_uart_init.c | Baud rate calc, register configuration |
| 02_uart_transmit.c | Sending bytes, strings, buffers |
| 03_uart_receive.c | Ring buffer, ISR-based receive |
| 04_uart_string_send.c | Formatted output, protocol frames |
| 05_uart_echo.c | Echo test + command interpreter |

## Key Formula
```
UBRR = (F_CPU / (16 * BAUD_RATE)) - 1
```

## Interview Notes
- UART is **asynchronous** — no clock line, both sides agree on baud rate
- **Ring buffer** (circular buffer) is standard for UART RX in firmware
- ISR should only put byte in buffer — main loop processes it
- Common baud rates: 9600, 115200
- 8N1 = 8 data bits, No parity, 1 stop bit (most common)

## Common Peripherals Using UART
- GPS modules (NMEA sentences at 9600 baud)
- Bluetooth HC-05 (9600 default)
- GSM SIM800L (AT commands)
- Debug console (115200)
