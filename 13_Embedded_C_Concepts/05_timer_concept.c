/*
 * Program  : Timer Concepts in Embedded C
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * Timers are hardware modules inside MCU that count clock cycles.
 * Used for: delays, periodic interrupts, PWM, input capture, etc.
 *
 * Timer Period formula:
 * Period = (ARR + 1) * (PSC + 1) / f_clock
 * Where: ARR = Auto-Reload Register, PSC = Prescaler
 *
 * Expected Output:
 * Timer configuration calculations
 */

#include <stdio.h>

#define MCU_CLOCK_HZ    72000000UL  /* 72 MHz for STM32F103 */
#define DESIRED_FREQ_HZ 1000        /* 1kHz = 1ms period */

int main()
{
    printf("=== Timer Concepts ===\n\n");

    /* Timer calculation */
    unsigned long psc = 71;          /* Prescaler: divides clock by (PSC+1) */
    unsigned long arr = 999;          /* Auto-Reload: counts up to ARR */
    unsigned long timer_clk = MCU_CLOCK_HZ / (psc + 1);
    float period_us = (float)(arr + 1) / timer_clk * 1e6f;
    float freq_hz   = 1.0f / (period_us / 1e6f);

    printf("MCU Clock     : %lu Hz\n", MCU_CLOCK_HZ);
    printf("Prescaler     : %lu (divides by %lu)\n", psc, psc + 1);
    printf("Timer Clock   : %lu Hz\n", timer_clk);
    printf("Auto-Reload   : %lu\n", arr);
    printf("Timer Period  : %.2f us\n", period_us);
    printf("Timer Freq    : %.2f Hz\n", freq_hz);

    printf("\n--- Common Timer Configurations ---\n");
    printf("For 1ms tick (1kHz):\n");
    printf("  PSC=71, ARR=999 -> 72MHz/(72*1000) = 1kHz\n\n");

    printf("For 1s (1Hz):\n");
    unsigned long psc_1s = 71;
    unsigned long arr_1s = 999999;
    float period_1s = (float)(arr_1s + 1) / (MCU_CLOCK_HZ / (psc_1s + 1));
    printf("  PSC=71, ARR=999999 -> Period = %.2f s\n", period_1s);

    printf("\n--- Software Delay using Timer Tick ---\n");
    printf("volatile uint32_t tick = 0;  // incremented in TIM ISR\n");
    printf("\nvoid delay_ms(uint32_t ms)\n{\n");
    printf("    uint32_t start = tick;\n");
    printf("    while((tick - start) < ms);  // busy wait\n");
    printf("}\n");

    printf("\n--- Timer Modes ---\n");
    printf("1. Basic Timer     : just counts, triggers interrupt on overflow\n");
    printf("2. Output Compare  : generates signal at specific count (PWM!)\n");
    printf("3. Input Capture   : measures signal timing (period/freq measurement)\n");
    printf("4. Encoder Mode    : counts quadrature encoder pulses\n");

    return 0;
}
