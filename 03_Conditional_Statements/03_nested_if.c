/*
 * Program  : Nested if Statement
 * Author   : PAVAN SHETTY H S
 * Topic    : Conditional Statements
 *
 * Description:
 * if inside another if is called nested if.
 * Example: A system that requires BOTH conditions to be true.
 *
 * Expected Output:
 * System powered ON
 * User authenticated
 * Access Granted! Welcome.
 */

#include <stdio.h>

int main()
{
    int power_on   = 1;   /* 1 = system is on */
    int auth_ok    = 1;   /* 1 = authentication passed */
    int door_open  = 0;   /* 0 = door is closed (good!) */

    if (power_on)
    {
        printf("System powered ON\n");

        if (auth_ok)
        {
            printf("User authenticated\n");

            if (!door_open)  /* !0 = 1 = door is closed = safe */
            {
                printf("Access Granted! Welcome.\n");
            }
            else
            {
                printf("Door is open! Cannot proceed.\n");
            }
        }
        else
        {
            printf("Authentication failed! Access Denied.\n");
        }
    }
    else
    {
        printf("System is OFF. Cannot proceed.\n");
    }

    return 0;
}
