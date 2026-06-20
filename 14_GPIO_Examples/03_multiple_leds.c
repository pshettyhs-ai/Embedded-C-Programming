/*
 * Program  : Controlling Multiple LEDs
 * Author   : PAVAN SHETTY H S
 * Topic    : GPIO Examples
 *
 * Control 8 LEDs connected to a full GPIO port (like PORTA or PORTB).
 * Using bitwise operations to control individual LEDs.
 *
 * Expected Output:
 * LED patterns on PORT B (8 LEDs)
 */

#include <stdio.h>
#include <stdint.h>

static uint8_t SIM_PORTB = 0x00;  /* 8-bit LED port */

void PORT_Write(uint8_t value)
{
    SIM_PORTB = value;
}

void LED_Set(int led_num)    /* led_num: 0-7 */
{
    SIM_PORTB |=  (1U << led_num);
}

void LED_Clear(int led_num)
{
    SIM_PORTB &= ~(1U << led_num);
}

void LED_Toggle(int led_num)
{
    SIM_PORTB ^=  (1U << led_num);
}

void print_port(const char *label)
{
    printf("%-20s: 0x%02X  [", label, SIM_PORTB);
    int i;
    for(i = 7; i >= 0; i--)
        printf("%c", (SIM_PORTB >> i) & 1 ? '*' : '.');
    printf("]\n");
}

void delay_ms(int ms) { (void)ms; }

int main()
{
    printf("=== Multiple LED Control ===\n");
    printf("(* = LED ON, . = LED OFF)\n\n");

    /* All off */
    PORT_Write(0x00);
    print_port("All OFF");

    /* All on */
    PORT_Write(0xFF);
    print_port("All ON");

    /* Individual LEDs */
    PORT_Write(0x00);
    int i;
    printf("\n--- Individual LED scan ---\n");
    for(i = 0; i < 8; i++)
    {
        PORT_Write(1U << i);
        char label[30];
        sprintf(label, "LED %d ON", i);
        print_port(label);
        delay_ms(100);
    }

    /* Patterns */
    printf("\n--- Patterns ---\n");
    PORT_Write(0xAA); print_port("0xAA alternating");  /* 10101010 */
    PORT_Write(0x55); print_port("0x55 alternating");  /* 01010101 */
    PORT_Write(0x0F); print_port("0x0F lower half");   /* 00001111 */
    PORT_Write(0xF0); print_port("0xF0 upper half");   /* 11110000 */

    /* Knight Rider / Chaser effect */
    printf("\n--- Knight Rider Effect ---\n");
    for(i = 0; i < 8; i++)
    {
        PORT_Write(1U << i);
        print_port(">>>");
        delay_ms(100);
    }
    for(i = 6; i >= 1; i--)
    {
        PORT_Write(1U << i);
        print_port("<<<");
        delay_ms(100);
    }

    return 0;
}
