/*
 * Program  : LED Pattern Generator
 * Author   : PAVAN SHETTY H S
 * Topic    : GPIO Examples
 *
 * Different LED patterns using lookup tables and bitwise operations.
 * Great for 7-segment, LED matrix, and decoration lighting projects.
 *
 * Expected Output:
 * Various LED patterns
 */

#include <stdio.h>
#include <stdint.h>

static uint8_t LED_PORT = 0x00;

/* Lookup table for patterns */
const uint8_t PATTERN_TABLE[] = {
    0x01,  /* 00000001 */
    0x03,  /* 00000011 */
    0x07,  /* 00000111 */
    0x0F,  /* 00001111 */
    0x1F,  /* 00011111 */
    0x3F,  /* 00111111 */
    0x7F,  /* 01111111 */
    0xFF,  /* 11111111 */
    0x7F,
    0x3F,
    0x1F,
    0x0F,
    0x07,
    0x03,
    0x01,
    0x00
};

void print_leds(const char *name, uint8_t val)
{
    printf("%-18s: [", name);
    int i;
    for(i = 7; i >= 0; i--)
        printf("%c", (val >> i) & 1 ? '#' : '-');
    printf("]\n");
}

void delay_ms(int ms) { (void)ms; }

int main()
{
    printf("=== LED Patterns (# = ON, - = OFF) ===\n\n");

    int i;
    printf("--- Fill and Drain ---\n");
    for(i = 0; i < 16; i++)
    {
        LED_PORT = PATTERN_TABLE[i];
        print_leds("", LED_PORT);
        delay_ms(100);
    }

    printf("\n--- Binary Counter (0-15) ---\n");
    for(i = 0; i <= 15; i++)
    {
        char label[20];
        sprintf(label, "Count %2d", i);
        print_leds(label, (uint8_t)i);
        delay_ms(200);
    }

    printf("\n--- Shift Left ---\n");
    uint8_t val = 0x01;
    for(i = 0; i < 8; i++)
    {
        print_leds("<<", val);
        val <<= 1;
        delay_ms(100);
    }

    printf("\n--- Shift Right ---\n");
    val = 0x80;
    for(i = 0; i < 8; i++)
    {
        print_leds(">>", val);
        val >>= 1;
        delay_ms(100);
    }

    return 0;
}
