/*
 * Program  : #define and Simple Macros
 * Author   : PAVAN SHETTY H S
 * Topic    : Preprocessor Directives
 *
 * #define creates constants and macros.
 * In embedded: register addresses, pin numbers, baud rates, etc.
 *
 * Expected Output:
 * LED_PIN = 13
 * MCU_FREQ = 16000000
 * MAX_BUFFER = 64
 */

#include <stdio.h>

/* Hardware constants (very common in embedded!) */
#define LED_PIN       13
#define BUTTON_PIN    2
#define MCU_FREQ      16000000UL    /* 16 MHz, UL = unsigned long */
#define BAUD_RATE     9600
#define MAX_BUFFER    64

/* Register address simulation (in real MCU this is actual address) */
#define GPIOA_BASE    0x40020000
#define GPIOA_ODR     (GPIOA_BASE + 0x14)
#define GPIOA_IDR     (GPIOA_BASE + 0x10)

/* Physical constants */
#define PI            3.14159265f
#define GRAVITY       9.81f

int main()
{
    printf("Hardware Configuration:\n");
    printf("LED_PIN    = %d\n",  LED_PIN);
    printf("BUTTON_PIN = %d\n",  BUTTON_PIN);
    printf("MCU_FREQ   = %lu Hz\n", MCU_FREQ);
    printf("BAUD_RATE  = %d\n",  BAUD_RATE);
    printf("MAX_BUFFER = %d\n",  MAX_BUFFER);

    printf("\nRegister Addresses:\n");
    printf("GPIOA_BASE = 0x%08X\n", GPIOA_BASE);
    printf("GPIOA_ODR  = 0x%08X\n", GPIOA_ODR);
    printf("GPIOA_IDR  = 0x%08X\n", GPIOA_IDR);

    /* Using constants in calculations */
    float radius = 5.0f;
    printf("\nCircle area (r=%.1f): %.2f\n", radius, PI * radius * radius);

    float height = 10.0f;
    float time   = 1.43f;  /* seconds to fall */
    float velocity = GRAVITY * time;
    printf("Falling velocity (h=%.0fm, t=%.2fs): %.2f m/s\n",
           height, time, velocity);

    return 0;
}
