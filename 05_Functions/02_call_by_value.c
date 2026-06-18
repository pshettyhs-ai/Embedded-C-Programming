/*
 * Program  : Call by Value in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Functions
 *
 * Call by Value: a COPY of the variable is passed.
 * Changes inside the function do NOT affect the original variable.
 *
 * Expected Output:
 * Before swap: a = 10, b = 20
 * Inside swap: a = 20, b = 10
 * After swap:  a = 10, b = 20  (original NOT changed!)
 */

#include <stdio.h>

void swap_by_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swap: a = %d, b = %d\n", a, b);
}

void modify(int x)
{
    x = x * 2;
    printf("Inside modify: x = %d\n", x);
}

int main()
{
    int a = 10, b = 20;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap_by_value(a, b);
    printf("After swap:  a = %d, b = %d\n", a, b);
    printf("(Original values are NOT changed - this is call by value!)\n");

    printf("\n--- Modify Example ---\n");
    int num = 5;
    printf("Before modify: num = %d\n", num);
    modify(num);
    printf("After modify:  num = %d\n", num);
    printf("(num is unchanged because it was passed by value)\n");

    return 0;
}
