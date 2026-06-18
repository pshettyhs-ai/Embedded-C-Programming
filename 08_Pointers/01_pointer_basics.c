/*
 * Program  : Pointer Basics in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * A pointer is a variable that stores a MEMORY ADDRESS.
 * Pointers are the most powerful (and tricky) concept in C.
 * In embedded: used for memory-mapped registers, buffers, function pointers.
 *
 * Key Operators:
 *   &  = address-of operator  (gives address of a variable)
 *   *  = dereference operator (gives value at that address)
 *
 * Expected Output:
 * Value of x     : 10
 * Address of x   : 0x7ffd... (some hex address)
 * Value via ptr  : 10
 */

#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr;        /* declare a pointer to int */

    ptr = &x;        /* store address of x in ptr */

    printf("Value of x       : %d\n",  x);
    printf("Address of x     : %p\n",  &x);
    printf("ptr holds address: %p\n",  ptr);
    printf("Value via ptr    : %d\n",  *ptr);  /* dereference */

    /* Modify x through pointer */
    *ptr = 50;
    printf("\nAfter *ptr = 50:\n");
    printf("x = %d (changed via pointer!)\n", x);

    /* Pointer size - always same regardless of type */
    int    *int_ptr;
    char   *char_ptr;
    float  *float_ptr;
    printf("\nPointer sizes:\n");
    printf("sizeof(int*)   = %lu bytes\n", sizeof(int_ptr));
    printf("sizeof(char*)  = %lu bytes\n", sizeof(char_ptr));
    printf("sizeof(float*) = %lu bytes\n", sizeof(float_ptr));
    printf("(All pointers are same size on a given system)\n");

    /* NULL pointer - pointer that points to nothing */
    int *null_ptr = NULL;
    printf("\nnull_ptr = %p\n", null_ptr);
    printf("Always check for NULL before dereferencing!\n");

    /* Embedded: Access a hardware register via pointer */
    /* In real MCU: volatile unsigned int *GPIO_OUT = (volatile unsigned int*)0x40020014; */
    printf("\nEmbedded register access example (simulated):\n");
    unsigned int fake_reg = 0x00;
    unsigned int *reg_ptr = &fake_reg;
    *reg_ptr |= (1 << 3);  /* Set bit 3 */
    printf("Register after setting bit3: 0x%02X\n", fake_reg);

    return 0;
}
