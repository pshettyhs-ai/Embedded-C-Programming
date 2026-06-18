/*
 * Program  : Call by Reference in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Functions
 *
 * Call by Reference: the ADDRESS (pointer) of the variable is passed.
 * Changes inside the function DO affect the original variable.
 * This is done using pointers.
 *
 * Expected Output:
 * Before swap: a = 10, b = 20
 * After swap:  a = 20, b = 10  (actually swapped!)
 */

#include <stdio.h>

/* Pass addresses using pointers */
void swap_by_reference(int *a, int *b)
{
    int temp = *a;  /* dereference: get value at address */
    *a = *b;
    *b = temp;
}

/* Useful: function to calculate both area and perimeter */
void circle_calc(float radius, float *area, float *perimeter)
{
    *area      = 3.14159f * radius * radius;
    *perimeter = 2 * 3.14159f * radius;
    /* Now both results are returned through pointers */
}

int main()
{
    int a = 10, b = 20;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap_by_reference(&a, &b);  /* pass addresses using & */
    printf("After swap:  a = %d, b = %d\n", a, b);

    printf("\n--- Circle Calculations ---\n");
    float r = 5.0f, area, perimeter;
    circle_calc(r, &area, &perimeter);
    printf("Radius    = %.2f\n", r);
    printf("Area      = %.2f\n", area);
    printf("Perimeter = %.2f\n", perimeter);

    /* Interview Note:
     * Q: What's the difference between call by value and call by reference?
     * A: Call by value = copy passed, original unchanged.
     *    Call by reference = address passed, original CAN be changed.
     *    In embedded, we pass pointers to structs/buffers to avoid
     *    copying large amounts of data (saves stack memory on MCU!)
     */

    return 0;
}
