/*
 * Program  : PWM (Pulse Width Modulation) Concepts
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * PWM = digital signal that switches between HIGH and LOW
 * at a fixed frequency, but with variable duty cycle.
 *
 * Duty Cycle = (ON time / Total period) * 100%
 * 0%  = always LOW  (motor off, LED off)
 * 50% = half ON, half OFF (motor at 50% speed)
 * 100%=always HIGH  (motor full speed, LED full brightness)
 *
 * Applications:
 * - LED brightness control
 * - Motor speed control (with H-bridge)
 * - Servo motor positioning
 * - Audio tone generation
 *
 * Expected Output:
 * PWM calculations and configurations
 */

#include <stdio.h>

void print_pwm_wave(int duty_percent, int width)
{
    /* Visual representation of PWM wave */
    int high_chars = (duty_percent * width) / 100;
    int low_chars  = width - high_chars;
    int i;

    printf("[");
    for(i = 0; i < high_chars; i++) printf("H");
    for(i = 0; i < low_chars; i++)  printf("L");
    printf("] %d%%\n", duty_percent);
}

int main()
{
    printf("=== PWM Concepts ===\n\n");

    /* PWM visual representation */
    printf("PWM Waveforms (H=HIGH, L=LOW):\n");
    printf("0%%  : "); print_pwm_wave(0,   20);
    printf("25%% : "); print_pwm_wave(25,  20);
    printf("50%% : "); print_pwm_wave(50,  20);
    printf("75%% : "); print_pwm_wave(75,  20);
    printf("100%%: "); print_pwm_wave(100, 20);

    /* PWM frequency and period */
    printf("\n--- PWM Configuration Example ---\n");
    unsigned long mcu_clk   = 72000000;  /* 72 MHz */
    unsigned long psc       = 71;         /* prescaler */
    unsigned long arr       = 999;         /* period */
    unsigned long timer_clk = mcu_clk / (psc + 1);
    float pwm_freq   = (float)timer_clk / (arr + 1);
    float pwm_period = 1.0f / pwm_freq * 1000.0f;  /* in ms */

    printf("Timer Clock : %lu Hz\n", timer_clk);
    printf("PWM Freq    : %.1f Hz\n", pwm_freq);
    printf("PWM Period  : %.2f ms\n", pwm_period);

    /* Duty cycle calculation */
    printf("\n--- Duty Cycle to CCR Value ---\n");
    printf("CCR = (Duty%% / 100) * (ARR + 1)\n");
    int duties[] = {0, 25, 50, 75, 100};
    int d;
    for(d = 0; d < 5; d++)
    {
        unsigned long ccr = (unsigned long)(duties[d] / 100.0f * (arr + 1));
        printf("Duty=%3d%% -> CCR = %lu\n", duties[d], ccr);
    }

    /* Servo motor control */
    printf("\n--- Servo Motor PWM (50Hz, 20ms period) ---\n");
    printf("Servo needs 50Hz PWM signal\n");
    printf("Position 0 deg  : 1ms  pulse (5%%  duty)\n");
    printf("Position 90 deg : 1.5ms pulse (7.5%% duty)\n");
    printf("Position 180 deg: 2ms  pulse (10%% duty)\n");

    /* LED brightness */
    printf("\n--- LED Brightness Control ---\n");
    int brightness;
    for(brightness = 0; brightness <= 100; brightness += 20)
        printf("Brightness %3d%%: PWM duty = %d%%\n", brightness, brightness);

    return 0;
}
