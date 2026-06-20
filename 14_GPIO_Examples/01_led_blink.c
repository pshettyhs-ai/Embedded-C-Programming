/*
 * Program  : LED Blink - The "Hello World" of Embedded Systems!
 * Author   : PAVAN SHETTY H S
 * Topic    : GPIO Examples
 * Target   : Generic ARM/AVR MCU (register-level style)
 *
 * This is the most basic embedded program.
 * Just like "Hello World" for software, LED blink is the
 * first program every embedded engineer writes!
 *
 * For STM32F103 (Blue Pill):
 * - Onboard LED is on PC13
 * - PC13 is active LOW (LED ON when pin is LOW)
 *
 * For Arduino:
 * - Onboard LED is on pin 13 (PB5)
 *
 * This file shows the concept with simulated register access.
 */

#include <stdio.h>
#include <stdint.h>

/* ===== Simulated Registers ===== */
static uint32_t SIM_RCC_APB2ENR = 0;   /* Clock enable register */
static uint32_t SIM_GPIOC_CRH   = 0;   /* Port C config register high */
static uint32_t SIM_GPIOC_ODR   = 0;   /* Port C output data register */

/* ===== Bit definitions ===== */
#define RCC_APB2ENR_IOPCEN  (1U << 4)   /* GPIOC clock enable */
#define LED_PIN             13
#define LED_PIN_MASK        (1U << LED_PIN)

/* ===== Simulated HAL functions ===== */
void delay_ms(uint32_t ms)
{
    /* In real MCU: hardware timer or SysTick */
    /* Here: just print it */
    (void)ms;  /* suppress unused warning */
}

void GPIO_LED_Init(void)
{
    /* Step 1: Enable GPIOC clock */
    SIM_RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
    printf("[INIT] GPIOC clock enabled. RCC_APB2ENR = 0x%08X\n", SIM_RCC_APB2ENR);

    /* Step 2: Configure PC13 as output (push-pull) */
    /* In GPIOC_CRH: bits 23:20 control PC13 (MODE13=01, CNF13=00) */
    SIM_GPIOC_CRH &= ~(0xFU << 20);  /* clear 4 bits for PC13 */
    SIM_GPIOC_CRH |=  (0x2U << 20);  /* MODE=10 (output 2MHz), CNF=00 (push-pull) */
    printf("[INIT] PC13 configured as OUTPUT. GPIOC_CRH = 0x%08X\n", SIM_GPIOC_CRH);

    /* Step 3: Turn LED OFF initially (PC13 is active LOW, so set HIGH = LED OFF) */
    SIM_GPIOC_ODR |= LED_PIN_MASK;
    printf("[INIT] LED initially OFF (PC13 HIGH). ODR = 0x%08X\n\n", SIM_GPIOC_ODR);
}

void LED_On(void)
{
    SIM_GPIOC_ODR &= ~LED_PIN_MASK;  /* PC13 LOW = LED ON */
}

void LED_Off(void)
{
    SIM_GPIOC_ODR |= LED_PIN_MASK;   /* PC13 HIGH = LED OFF */
}

void LED_Toggle(void)
{
    SIM_GPIOC_ODR ^= LED_PIN_MASK;
}

int main()
{
    printf("=== LED Blink Program ===\n");
    printf("Target: STM32F103 (Blue Pill), LED on PC13 (Active LOW)\n\n");

    /* Initialize GPIO */
    GPIO_LED_Init();

    /* Blink LED 5 times */
    printf("[BLINK] Starting LED blink sequence...\n");
    int i;
    for(i = 0; i < 5; i++)
    {
        LED_On();
        printf("Blink %d: LED ON  (PC13=LOW,  ODR=0x%04X)\n", i+1, SIM_GPIOC_ODR & 0xFFFF);
        delay_ms(500);

        LED_Off();
        printf("Blink %d: LED OFF (PC13=HIGH, ODR=0x%04X)\n", i+1, SIM_GPIOC_ODR & 0xFFFF);
        delay_ms(500);
    }

    /* Toggle using XOR */
    printf("\n[TOGGLE] Toggle mode:\n");
    for(i = 0; i < 6; i++)
    {
        LED_Toggle();
        printf("Toggle %d: PC13 = %s\n", i+1,
               (SIM_GPIOC_ODR & LED_PIN_MASK) ? "HIGH (OFF)" : "LOW (ON)");
        delay_ms(250);
    }

    printf("\n[DONE] LED blink complete.\n");
    printf("\nReal MCU main() would have: while(1) { LED_Toggle(); delay_ms(500); }\n");

    return 0;
}
