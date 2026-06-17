/*
 * Program  : Logical Operators in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Operators
 *
 * && = AND (both must be true)
 * || = OR  (at least one must be true)
 * !  = NOT (reverses the result)
 *
 * Expected Output:
 * AND: 1 && 0 = 0
 * OR:  1 || 0 = 1
 * NOT: !1     = 0
 */

#include <stdio.h>

int main()
{
    int x = 1, y = 0;

    printf("--- Logical Operators ---\n");
    printf("AND: %d && %d = %d\n", x, y, x && y);
    printf("OR:  %d || %d = %d\n", x, y, x || y);
    printf("NOT: !%d     = %d\n",  x, !x);

    /* Embedded Example: Check multiple conditions for a safety system */
    int button_pressed   = 1;   /* 1 = pressed */
    int door_closed      = 1;   /* 1 = closed */
    int temperature_ok   = 0;   /* 0 = too hot! */

    printf("\n--- Safety System Check ---\n");
    printf("Button: %d, Door: %d, Temp OK: %d\n",
           button_pressed, door_closed, temperature_ok);

    /* Machine should start ONLY if all conditions are good */
    if (button_pressed && door_closed && temperature_ok)
        printf("Machine Started!\n");
    else
        printf("Cannot start. Check all conditions.\n");

    /* Alert if button pressed OR temperature too high */
    if (button_pressed || !temperature_ok)
        printf("Alert: Attention needed!\n");

    return 0;
}
