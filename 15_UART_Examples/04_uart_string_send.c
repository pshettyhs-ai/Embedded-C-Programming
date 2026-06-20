/*
 * Program  : UART String Formatting and Sending
 * Author   : PAVAN SHETTY H S
 * Topic    : UART Communication
 *
 * Sending formatted data over UART:
 * - Sensor readings
 * - Debug messages
 * - Protocol frames with checksum
 *
 * Expected Output:
 * Various formatted UART messages
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Simulated TX output buffer */
static char tx_output[512];
static int  tx_pos = 0;

void UART_SendByte(uint8_t c)
{
    tx_output[tx_pos++] = (char)c;
    tx_output[tx_pos]   = '\0';
}

void UART_SendString(const char *s)
{
    while(*s) UART_SendByte((uint8_t)*s++);
}

void UART_Printf(const char *fmt, ...)
{
    char buf[128];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    UART_SendString(buf);
}

/* Calculate simple checksum */
uint8_t calc_checksum(const uint8_t *data, int len)
{
    uint8_t sum = 0;
    int i;
    for(i = 0; i < len; i++) sum += data[i];
    return ~sum + 1;  /* two's complement */
}

#include <stdarg.h>

int main()
{
    printf("=== UART String Send Demo ===\n\n");

    /* 1. Simple status messages */
    printf("1. Status messages:\n");
    UART_SendString("System initialized\r\n");
    UART_SendString("Waiting for sensor data...\r\n");
    printf("   TX: %s", tx_output);
    tx_pos = 0;

    /* 2. Formatted sensor data */
    printf("\n2. Formatted sensor data:\n");
    int   temp     = 28;
    float humidity = 65.4f;
    int   pressure = 1013;
    UART_Printf("TEMP=%d C, HUM=%.1f %%, PRES=%d hPa\r\n",
                temp, humidity, pressure);
    printf("   TX: %s", tx_output);
    tx_pos = 0;

    /* 3. CSV format (easy to log to PC) */
    printf("\n3. CSV format:\n");
    UART_Printf("timestamp,temperature,humidity,pressure\r\n");
    UART_Printf("001,%d,%.1f,%d\r\n", temp, humidity, pressure);
    printf("   TX: %s", tx_output);
    tx_pos = 0;

    /* 4. Debug messages with prefix */
    printf("\n4. Debug messages:\n");
    UART_Printf("[INFO]  Boot complete\r\n");
    UART_Printf("[WARN]  Voltage low: 3.1V\r\n");
    UART_Printf("[ERROR] Sensor timeout!\r\n");
    printf("   TX: %s", tx_output);
    tx_pos = 0;

    /* 5. Binary protocol frame */
    printf("\n5. Binary protocol frame:\n");
    uint8_t payload[] = {0x01, 0x1C, 0x00};  /* cmd, temp, status */
    uint8_t chk = calc_checksum(payload, 3);
    uint8_t frame[] = {0xAA, 0x55, 0x03, 0x01, 0x1C, 0x00, chk};
    /* Preamble=0xAA55, Len=0x03, Data..., Checksum */
    printf("   Frame: ");
    int i;
    for(i = 0; i < (int)sizeof(frame); i++)
        printf("0x%02X ", frame[i]);
    printf("\n");
    printf("   Checksum: 0x%02X\n", chk);

    return 0;
}
