/*
 * Program  : Structure Basics in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * A struct groups different data types under one name.
 * In embedded: GPIO config, UART config, sensor data, packets.
 *
 * Expected Output:
 * Sensor ID: 1, Name: TempSensor, Value: 36.60, Unit: C
 */

#include <stdio.h>

/* Define a structure */
struct Sensor {
    int   id;
    char  name[30];
    float value;
    char  unit[5];
};

/* Embedded: UART configuration structure */
struct UART_Config {
    unsigned int  baud_rate;
    unsigned char data_bits;  /* 8 */
    unsigned char stop_bits;  /* 1 */
    unsigned char parity;     /* 0=none, 1=even, 2=odd */
};

int main()
{
    /* Declare and initialize struct */
    struct Sensor s1;
    s1.id    = 1;
    strcpy(s1.name, "TempSensor");
    s1.value = 36.6f;
    strcpy(s1.unit, "C");

    /* Print struct fields */
    printf("Sensor ID   : %d\n",   s1.id);
    printf("Sensor Name : %s\n",   s1.name);
    printf("Sensor Value: %.2f\n", s1.value);
    printf("Sensor Unit : %s\n",   s1.unit);

    /* Struct initialization at declaration */
    struct Sensor s2 = {2, "HumiditySensor", 65.5f, "%"};
    printf("\nSensor 2: ID=%d Name=%s Value=%.1f%s\n",
           s2.id, s2.name, s2.value, s2.unit);

    /* UART config */
    struct UART_Config uart1 = {9600, 8, 1, 0};
    printf("\nUART Config:\n");
    printf("  Baud Rate : %u\n", uart1.baud_rate);
    printf("  Data Bits : %u\n", uart1.data_bits);
    printf("  Stop Bits : %u\n", uart1.stop_bits);
    printf("  Parity    : %s\n", uart1.parity == 0 ? "None" :
                                  uart1.parity == 1 ? "Even" : "Odd");

    printf("\nSize of Sensor struct: %lu bytes\n", sizeof(struct Sensor));
    printf("Size of UART_Config:   %lu bytes\n",   sizeof(struct UART_Config));

    return 0;
}
