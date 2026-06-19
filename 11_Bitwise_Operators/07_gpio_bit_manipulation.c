/*
 * Program  : GPIO Register Manipulation using Bitwise Ops
 * Author   : PAVAN SHETTY H S
 * Topic    : Bitwise Operators
 *
 * This program simulates real MCU GPIO register access.
 * In actual embedded code (e.g. STM32):
 *   GPIOA->ODR  |= GPIO_PIN_5;   // Set PA5 HIGH
 *   GPIOA->ODR  &= ~GPIO_PIN_5;  // Set PA5 LOW
 *   GPIOA->ODR  ^= GPIO_PIN_5;   // Toggle PA5
 *
 * Expected Output:
 * (simulated GPIO port operations)
 */

#include <stdio.h>

/* Simulated MCU registers (in real MCU these are memory-mapped addresses) */
typedef unsigned int uint32_t;

uint32_t GPIOA_MODER = 0x00000000;  /* Mode register */
uint32_t GPIOA_ODR   = 0x00000000;  /* Output data register */
uint32_t GPIOA_IDR   = 0x00000000;  /* Input data register */

/* Pin definitions */
#define PIN_0  (1U << 0)
#define PIN_1  (1U << 1)
#define PIN_2  (1U << 2)
#define PIN_3  (1U << 3)
#define PIN_4  (1U << 4)
#define PIN_5  (1U << 5)
#define PIN_13 (1U << 13)

/* Mode definitions */
#define GPIO_MODE_INPUT  0
#define GPIO_MODE_OUTPUT 1

void GPIO_SetMode(uint32_t *moder, int pin, int mode)
{
    /* Each pin uses 2 bits in MODER */
    *moder &= ~(0x3U << (pin * 2));      /* clear 2 bits */
    *moder |=  ((uint32_t)mode << (pin * 2));  /* set mode */
}

void GPIO_Write(uint32_t *odr, uint32_t pin, int state)
{
    if(state) *odr |=  pin;   /* set HIGH */
    else      *odr &= ~pin;   /* set LOW  */
}

void GPIO_Toggle(uint32_t *odr, uint32_t pin)
{
    *odr ^= pin;
}

int GPIO_Read(uint32_t idr, uint32_t pin)
{
    return (idr & pin) ? 1 : 0;
}

void print_port(const char *label, uint32_t port)
{
    printf("%-15s: 0x%04X  [", label, port & 0xFFFF);
    int i;
    for(i = 15; i >= 0; i--)
    {
        printf("%d", (port >> i) & 1);
        if(i % 4 == 0 && i > 0) printf(" ");
    }
    printf("]\n");
}

int main()
{
    printf("=== GPIO Register Simulation ===\n\n");

    /* Configure pins as output */
    GPIO_SetMode(&GPIOA_MODER, 5, GPIO_MODE_OUTPUT);   /* PA5 = output (onboard LED) */
    GPIO_SetMode(&GPIOA_MODER, 13, GPIO_MODE_OUTPUT);  /* PA13 = output */
    printf("After setting PA5, PA13 as OUTPUT:\n");
    print_port("GPIOA_MODER", GPIOA_MODER);

    /* Write HIGH/LOW */
    printf("\nSetting PA5 HIGH (LED ON):\n");
    GPIO_Write(&GPIOA_ODR, PIN_5, 1);
    print_port("GPIOA_ODR", GPIOA_ODR);

    printf("\nSetting PA13 HIGH:\n");
    GPIO_Write(&GPIOA_ODR, PIN_13, 1);
    print_port("GPIOA_ODR", GPIOA_ODR);

    printf("\nClearing PA5 LOW (LED OFF):\n");
    GPIO_Write(&GPIOA_ODR, PIN_5, 0);
    print_port("GPIOA_ODR", GPIOA_ODR);

    /* Toggle LED */
    printf("\n--- Blinking LED (toggle PA13) ---\n");
    int i;
    for(i = 0; i < 4; i++)
    {
        GPIO_Toggle(&GPIOA_ODR, PIN_13);
        printf("Cycle %d: PA13 = %s\n", i+1,
               GPIO_Read(GPIOA_ODR, PIN_13) ? "HIGH (ON)" : "LOW (OFF)");
    }

    return 0;
}
