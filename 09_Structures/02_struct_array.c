/*
 * Program  : Array of Structures
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * You can have an array where each element is a struct.
 * Very useful for: student records, sensor arrays, GPIO pin table.
 *
 * Expected Output:
 * ID  Name            Value   Unit
 * 1   TempSensor      36.60   C
 * 2   PressureSensor  101.32  kPa
 * 3   HumiditySensor  65.50   %
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    int   id;
    char  name[30];
    float value;
    char  unit[5];
} Sensor;  /* using typedef so we don't need to write 'struct' every time */

int main()
{
    /* Array of 3 sensors */
    Sensor sensors[3] = {
        {1, "TempSensor",     36.60f, "C"  },
        {2, "PressureSensor", 101.32f,"kPa"},
        {3, "HumiditySensor", 65.50f, "%"  }
    };
    int n = 3, i;

    printf("%-4s %-20s %-8s %s\n", "ID", "Name", "Value", "Unit");
    printf("%-4s %-20s %-8s %s\n", "--", "----", "-----", "----");
    for(i = 0; i < n; i++)
    {
        printf("%-4d %-20s %-8.2f %s\n",
               sensors[i].id, sensors[i].name,
               sensors[i].value, sensors[i].unit);
    }

    /* Find sensor with highest reading */
    int max_idx = 0;
    for(i = 1; i < n; i++)
        if(sensors[i].value > sensors[max_idx].value)
            max_idx = i;

    printf("\nHighest reading: %s = %.2f %s\n",
           sensors[max_idx].name, sensors[max_idx].value, sensors[max_idx].unit);

    /* Embedded: GPIO pin configuration table */
    printf("\n--- GPIO Pin Config Table ---\n");
    typedef struct { int pin; char mode[10]; int state; } GPIO_Pin;

    GPIO_Pin pins[] = {
        {13, "OUTPUT", 1},
        {12, "OUTPUT", 0},
        {2,  "INPUT",  0},
        {3,  "INPUT",  1}
    };
    int pin_count = 4;

    printf("Pin  Mode    State\n");
    for(i = 0; i < pin_count; i++)
        printf("%-4d %-7s %s\n", pins[i].pin, pins[i].mode,
               pins[i].state ? "HIGH" : "LOW");

    return 0;
}
