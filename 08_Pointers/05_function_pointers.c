/*
 * Program  : Function Pointers
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * A function pointer stores the address of a function.
 * This allows calling different functions dynamically!
 * Very useful in embedded: callback functions, ISR tables, state machines.
 *
 * Expected Output:
 * Addition: 15
 * Subtraction: 5
 * (called through function pointer!)
 */

#include <stdio.h>

/* Regular functions */
int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

/* Function that takes no args, returns void (like ISR handlers) */
void led_on(void)  { printf("LED turned ON\n"); }
void led_off(void) { printf("LED turned OFF\n"); }
void led_blink(void){ printf("LED blinking\n"); }

int main()
{
    /* Declare function pointer: int (*name)(int, int) */
    int (*operation)(int, int);

    /* Assign and call */
    operation = add;
    printf("Add via pointer: %d\n", operation(10, 5));

    operation = subtract;
    printf("Sub via pointer: %d\n", operation(10, 5));

    operation = multiply;
    printf("Mul via pointer: %d\n", operation(10, 5));

    /* Array of function pointers - useful for menus / state machines */
    printf("\n--- LED State Machine ---\n");
    void (*led_state[3])(void) = {led_on, led_off, led_blink};
    char *state_names[] = {"ON", "OFF", "BLINK"};

    int i;
    for(i = 0; i < 3; i++)
    {
        printf("State %d (%s): ", i, state_names[i]);
        led_state[i]();  /* call function through pointer */
    }

    /* Interview Note:
     * Q: What are function pointers used for in embedded C?
     * A: Callback functions (e.g., register ISR handlers),
     *    Jump tables for state machines,
     *    Command dispatch tables (AT command parsers),
     *    Dynamic behavior selection at runtime.
     */

    return 0;
}
