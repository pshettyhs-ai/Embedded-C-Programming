/*
 * Program  : if-else Ladder
 * Author   : PAVAN SHETTY H S
 * Topic    : Conditional Statements
 *
 * Description:
 * if-else ladder is used when we have multiple conditions.
 * Practical example: voltage range checking in embedded systems.
 *
 * Expected Output:
 * ADC value: 512, Voltage: 2.50V
 * Voltage Level: Normal
 */

#include <stdio.h>

int main()
{
    /* Simulate ADC reading (0-1023 for 10-bit ADC) */
    int adc_value = 512;
    float voltage = (float)adc_value / 1023.0f * 5.0f;

    printf("ADC value: %d, Voltage: %.2fV\n", adc_value, voltage);

    /* Check voltage range */
    if (voltage < 1.0)
        printf("Voltage Level: Too Low! (Under-voltage)\n");
    else if (voltage >= 1.0 && voltage < 2.0)
        printf("Voltage Level: Low\n");
    else if (voltage >= 2.0 && voltage < 3.5)
        printf("Voltage Level: Normal\n");
    else if (voltage >= 3.5 && voltage < 4.5)
        printf("Voltage Level: High\n");
    else
        printf("Voltage Level: Too High! (Over-voltage)\n");

    /* Temperature monitoring example */
    int temp = 45;  /* Celsius */
    printf("\nTemperature: %d C\n", temp);

    if (temp < 0)
        printf("Status: Freezing\n");
    else if (temp < 20)
        printf("Status: Cold\n");
    else if (temp < 40)
        printf("Status: Normal\n");
    else if (temp < 80)
        printf("Status: Hot - Enable cooling fan\n");
    else
        printf("Status: Critical! Shutdown system!\n");

    return 0;
}
