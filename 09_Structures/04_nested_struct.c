/*
 * Program  : Nested Structures
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * A struct can contain another struct as a member.
 * Common in embedded: device config containing multiple sub-configs.
 *
 * Expected Output:
 * MCU: STM32F103
 * Clock: 72000000 Hz
 * UART Baud: 115200
 */

#include <stdio.h>

typedef struct {
    unsigned int  baud_rate;
    unsigned char data_bits;
    unsigned char stop_bits;
} UART_Config;

typedef struct {
    unsigned int freq_hz;
    unsigned char prescaler;
} Clock_Config;

/* Nested struct: MCU config contains sub-configs */
typedef struct {
    char         mcu_name[20];
    Clock_Config clock;     /* embedded struct */
    UART_Config  uart;      /* embedded struct */
    unsigned int flash_kb;
    unsigned int ram_kb;
} MCU_Config;

int main()
{
    MCU_Config mcu = {
        "STM32F103",
        {72000000, 1},     /* clock config */
        {115200, 8, 1},    /* uart config */
        128,               /* 128KB flash */
        20                 /* 20KB RAM */
    };

    printf("MCU Name    : %s\n",   mcu.mcu_name);
    printf("Clock Freq  : %u Hz\n",mcu.clock.freq_hz);
    printf("Prescaler   : %u\n",   mcu.clock.prescaler);
    printf("UART Baud   : %u\n",   mcu.uart.baud_rate);
    printf("Data Bits   : %u\n",   mcu.uart.data_bits);
    printf("Flash       : %u KB\n",mcu.flash_kb);
    printf("RAM         : %u KB\n",mcu.ram_kb);

    return 0;
}
