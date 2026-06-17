/*
 * Program  : switch-case Statement
 * Author   : PAVAN SHETTY H S
 * Topic    : Conditional Statements
 *
 * Description:
 * switch-case is better than if-else ladder when checking
 * a single variable against multiple fixed values.
 * Very common for menu-driven programs and state machines in embedded!
 *
 * Expected Output:
 * Enter operation (1-Add 2-Sub 3-Mul 4-Div): 2
 * Enter two numbers: 10 4
 * Result: 10 - 4 = 6
 */

#include <stdio.h>

int main()
{
    int choice;
    int a, b;

    printf("Enter operation:\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch(choice)
    {
        case 1:
            printf("Result: %d + %d = %d\n", a, b, a + b);
            break;  /* IMPORTANT: break exits the switch block */

        case 2:
            printf("Result: %d - %d = %d\n", a, b, a - b);
            break;

        case 3:
            printf("Result: %d * %d = %d\n", a, b, a * b);
            break;

        case 4:
            if (b != 0)
                printf("Result: %d / %d = %d\n", a, b, a / b);
            else
                printf("Error: Cannot divide by zero!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    /* Embedded Example: LED mode control */
    printf("\n--- LED Mode Controller ---\n");
    int mode = 2;  /* Mode selected */

    switch(mode)
    {
        case 0: printf("LED Mode: OFF\n");           break;
        case 1: printf("LED Mode: Always ON\n");     break;
        case 2: printf("LED Mode: Blinking\n");      break;
        case 3: printf("LED Mode: Breathing PWM\n"); break;
        default: printf("LED Mode: Unknown\n");      break;
    }

    /* Interview Note:
     * Q: What happens if we forget 'break' in switch-case?
     * A: It "falls through" to the next case and executes it too.
     *    This is called fall-through behavior. Sometimes used intentionally.
     */

    return 0;
}
