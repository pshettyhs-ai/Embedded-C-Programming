/*
 * Program  : Constants in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Basics of C
 *
 * Description:
 * Constants are values that don't change during program execution.
 * In embedded systems, we use constants a lot - for example,
 * pin numbers, baud rates, register addresses, etc.
 *
 * Expected Output:
 * LED Pin Number: 13
 * Baud Rate: 9600
 * Value of PI: 3.141593
 * Max ADC Value: 1023
 */

#include <stdio.h>

/* Method 1: Using #define (no memory used - just text replacement) */
#define LED_PIN     13
#define BAUD_RATE   9600
#define MAX_ADC     1023

/* Method 2: Using const keyword (occupies memory but type-safe) */
const float PI = 3.141593f;
const int   MCU_FREQ = 16000000;  /* 16 MHz clock */

int main()
{
    printf("LED Pin Number: %d\n",  LED_PIN);
    printf("Baud Rate: %d\n",       BAUD_RATE);
    printf("Value of PI: %f\n",     PI);
    printf("Max ADC Value: %d\n",   MAX_ADC);
    printf("MCU Frequency: %d Hz\n", MCU_FREQ);

    /* Interview Note:
     * Q: What is the difference between #define and const?
     * A: #define is handled by preprocessor (no type checking, no memory).
     *    const is handled by compiler (type-safe, occupies memory).
     *    In embedded C, #define is commonly used for register addresses.
     */

    return 0;
}
