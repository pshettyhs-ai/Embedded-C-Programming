/*
 * Program  : Header Guards and #pragma once
 * Author   : PAVAN SHETTY H S
 * Topic    : Preprocessor Directives
 *
 * Header guards prevent a header file from being included multiple times.
 * Without guards: multiple definition errors!
 *
 * This file demonstrates the concept with simulated header content.
 *
 * Standard header guard pattern (used in EVERY .h file):
 * #ifndef MY_HEADER_H
 * #define MY_HEADER_H
 * ... your declarations ...
 * #endif
 */

#include <stdio.h>

/* ===== Simulated content of "gpio.h" ===== */
#ifndef GPIO_H
#define GPIO_H

    #define GPIO_OUTPUT 1
    #define GPIO_INPUT  0
    #define GPIO_HIGH   1
    #define GPIO_LOW    0

    /* Function declarations */
    void gpio_init(int pin, int mode);
    void gpio_write(int pin, int state);
    int  gpio_read(int pin);

#endif  /* GPIO_H */
/* ========================================= */

/* ===== Simulated content of "uart.h" ===== */
#ifndef UART_H
#define UART_H

    #define UART_BAUD_9600   9600
    #define UART_BAUD_115200 115200

    void uart_init(int baud);
    void uart_send(unsigned char data);

#endif  /* UART_H */
/* ========================================= */

/* Dummy implementations for demo */
void gpio_init(int pin, int mode)
{
    printf("GPIO Pin %d configured as %s\n", pin,
           mode == GPIO_OUTPUT ? "OUTPUT" : "INPUT");
}
void gpio_write(int pin, int state)
{
    printf("GPIO Pin %d set %s\n", pin, state ? "HIGH" : "LOW");
}
int gpio_read(int pin) { return GPIO_HIGH; }

void uart_init(int baud) { printf("UART initialized at %d baud\n", baud); }
void uart_send(unsigned char data) { printf("UART sent: 0x%02X\n", data); }

int main()
{
    printf("=== Header Guard Demo ===\n\n");

    gpio_init(13, GPIO_OUTPUT);
    gpio_write(13, GPIO_HIGH);
    printf("GPIO Read: %d\n", gpio_read(2));

    uart_init(UART_BAUD_115200);
    uart_send(0x41);  /* 'A' */

    printf("\nWith header guards, including gpio.h twice causes no errors!\n");
    return 0;
}
