/*
 * Program  : LED Control with Button Input
 * Author   : PAVAN SHETTY H S
 * Topic    : GPIO Examples
 * Target   : Generic MCU (register-level style)
 *
 * Button controls LED:
 * - Button pressed  -> LED ON
 * - Button released -> LED OFF
 *
 * Demonstrates:
 * - GPIO input configuration (with pull-up)
 * - GPIO output configuration
 * - Button debouncing concept
 *
 * For STM32F103:
 * - Button on PA0 (active HIGH or LOW depending on circuit)
 * - LED on PC13 (active LOW)
 */

#include <stdio.h>
#include <stdint.h>

/* Simulated registers */
static uint32_t SIM_GPIOA_IDR = 0;   /* Input data (buttons) */
static uint32_t SIM_GPIOC_ODR = (1U << 13);  /* Output (LED OFF = HIGH) */

#define LED_PIN     13
#define BUTTON_PIN  0

void LED_Write(int state)
{
    if(state)
        SIM_GPIOC_ODR &= ~(1U << LED_PIN);   /* Active LOW: clear = LED ON */
    else
        SIM_GPIOC_ODR |=  (1U << LED_PIN);   /* Active LOW: set   = LED OFF */
}

int Button_Read(void)
{
    return (SIM_GPIOA_IDR >> BUTTON_PIN) & 1;  /* return pin state */
}

void delay_ms(uint32_t ms) { (void)ms; }

int main()
{
    printf("=== LED + Button Control ===\n\n");

    /* Simulate button press/release sequence */
    int sim_sequence[] = {0,0,1,1,1,0,0,1,0,0};
    int n = 10, i;

    printf("%-6s  %-10s  %-10s\n", "Cycle", "Button", "LED");
    printf("------  ----------  ----------\n");

    for(i = 0; i < n; i++)
    {
        /* Set simulated button state */
        if(sim_sequence[i])
            SIM_GPIOA_IDR |=  (1U << BUTTON_PIN);
        else
            SIM_GPIOA_IDR &= ~(1U << BUTTON_PIN);

        /* Read button and control LED */
        int btn = Button_Read();
        LED_Write(btn);  /* LED follows button */

        printf("%-6d  %-10s  %-10s\n",
               i+1,
               btn ? "PRESSED" : "released",
               (SIM_GPIOC_ODR & (1U << LED_PIN)) ? "OFF" : "ON");

        delay_ms(10);
    }

    printf("\n--- Debounce Concept ---\n");
    printf("Hardware buttons bounce (rapid 0/1) for ~5-50ms when pressed.\n");
    printf("Solution 1: Software delay - read, delay 20ms, read again\n");
    printf("Solution 2: Timer-based - compare two readings 20ms apart\n");
    printf("Solution 3: Hardware RC filter on button input\n");

    /* Debounce code pattern */
    printf("\nDebounce pattern:\n");
    printf("  if(GPIO_Read(BUTTON_PIN) == PRESSED)\n");
    printf("  {\n");
    printf("      delay_ms(20);  // wait for bounce to settle\n");
    printf("      if(GPIO_Read(BUTTON_PIN) == PRESSED)  // confirm\n");
    printf("          handle_button_press();\n");
    printf("  }\n");

    return 0;
}
