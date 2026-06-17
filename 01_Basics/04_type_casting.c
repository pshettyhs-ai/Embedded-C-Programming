/*
 * Program  : Type Casting in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Basics of C
 *
 * Description:
 * Type casting converts one data type to another.
 * This is important in embedded C when reading ADC values,
 * converting sensor data, etc.
 *
 * Expected Output:
 * Integer division: 5/2 = 2
 * Float division:   5/2 = 2.500000
 * ADC raw: 512, Voltage: 2.50V
 */

#include <stdio.h>

int main()
{
    int a = 5, b = 2;
    float result;

    /* Without type casting - integer division loses decimal part */
    printf("Integer division: %d/%d = %d\n", a, b, a/b);

    /* With type casting - now we get float result */
    result = (float)a / (float)b;
    printf("Float division:   %d/%d = %f\n", a, b, result);

    /* Practical Example: ADC value to voltage conversion */
    /* ADC is 10-bit (0 to 1023), Reference voltage = 5V */
    int adc_raw = 512;
    float voltage;
    float vref = 5.0f;

    voltage = ((float)adc_raw / 1023.0f) * vref;
    printf("\nADC raw: %d, Voltage: %.2fV\n", adc_raw, voltage);

    /* Implicit type casting example */
    int x = 300;
    char c = (char)x;  /* Will overflow! 300 doesn't fit in char */
    printf("\nImplicit overflow example: int %d stored in char = %d\n", x, c);
    printf("(This is a common bug in embedded programming!)\n");

    return 0;
}
