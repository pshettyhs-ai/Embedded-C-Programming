/*
 * Program  : Raw GPIO Register Access (AVR Style)
 * Author   : PAVAN SHETTY H S
 * Topic    : GPIO Examples
 * Target   : AVR ATmega328P (Arduino Uno compatible)
 *
 * AVR GPIO has 3 registers per port:
 * DDRx  = Data Direction Register (0=input, 1=output)
 * PORTx = Output register (write: set value; input: enable pull-up)
 * PINx  = Input register (read actual pin state)
 *
 * This is AVR-style bare-metal code (similar to real Arduino registers)
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated AVR registers */
static uint8_t DDRB  = 0x00;  /* Data direction for PORT B */
static uint8_t PORTB = 0x00;  /* Output/pull-up control for PORT B */
static uint8_t PINB  = 0x00;  /* Read actual pin state of PORT B */

static uint8_t DDRD  = 0x00;  /* Data direction for PORT D */
static uint8_t PORTD = 0x00;
static uint8_t PIND  = 0b00000100;  /* Simulate button on PD2 pressed */

/* AVR pin macros */
#define LED_PIN    5   /* PB5 = Arduino pin 13 (onboard LED) */
#define BUTTON_PIN 2   /* PD2 = Arduino pin 2 */

#define sbi(reg, bit) ((reg) |=  (1 << (bit)))  /* set bit */
#define cbi(reg, bit) ((reg) &= ~(1 << (bit)))  /* clear bit */
#define tbi(reg, bit) ((reg) ^=  (1 << (bit)))  /* toggle bit */
#define rbi(reg, bit) (((reg) >> (bit)) & 1)    /* read bit */

void print_registers(void)
{
    printf("DDRB=0x%02X PORTB=0x%02X PINB=0x%02X\n", DDRB, PORTB, PINB);
    printf("DDRD=0x%02X PORTD=0x%02X PIND=0x%02X\n\n", DDRD, PORTD, PIND);
}

int main()
{
    printf("=== AVR GPIO Register Access ===\n");
    printf("Target: ATmega328P (Arduino Uno)\n\n");

    /* Initial state */
    printf("Initial state:\n");
    print_registers();

    /* Configure LED pin (PB5) as output */
    sbi(DDRB, LED_PIN);
    printf("After sbi(DDRB, 5) - PB5 as OUTPUT:\n");
    print_registers();

    /* Configure button pin (PD2) as input with pull-up */
    cbi(DDRD, BUTTON_PIN);    /* set as input */
    sbi(PORTD, BUTTON_PIN);   /* enable internal pull-up */
    printf("After configuring PD2 as INPUT with pull-up:\n");
    print_registers();

    /* Read button and control LED */
    printf("--- Reading button, controlling LED ---\n");
    int button_state = rbi(PIND, BUTTON_PIN);
    printf("Button (PD2) state: %d (%s)\n", button_state,
           button_state ? "HIGH (not pressed, pull-up active)" : "LOW (pressed)");

    /* Toggle LED 4 times */
    printf("\n--- Toggling LED (PB5) ---\n");
    int i;
    for(i = 0; i < 4; i++)
    {
        tbi(PORTB, LED_PIN);
        PINB = PORTB;  /* in real AVR, PINB reflects actual pin state */
        printf("Toggle %d: PB5 = %d (%s)\n", i+1,
               rbi(PORTB, LED_PIN),
               rbi(PORTB, LED_PIN) ? "HIGH = LED ON (common anode)" : "LOW = LED ON (common cathode)");
    }

    printf("\nAVR/Arduino equivalent:\n");
    printf("  DDR  -> pinMode()   in Arduino\n");
    printf("  PORT -> digitalWrite() in Arduino\n");
    printf("  PIN  -> digitalRead()  in Arduino\n");

    return 0;
}
