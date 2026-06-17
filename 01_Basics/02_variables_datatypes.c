/*
 * Program  : Variables and Data Types in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Basics of C
 *
 * Description:
 * In embedded systems, choosing the right data type is very important
 * because microcontrollers have limited RAM.
 * For example: use uint8_t instead of int when you only need 0-255.
 *
 * Expected Output:
 * --- Integer Types ---
 * char value: 65 (ASCII: A)
 * int value: 32767
 * short value: 100
 * long value: 1000000
 * --- Float Types ---
 * float: 3.14
 * double: 3.141593
 * --- Sizes in bytes ---
 * Size of char: 1 bytes
 * Size of int: 4 bytes
 * Size of float: 4 bytes
 * Size of double: 8 bytes
 */

#include <stdio.h>

int main()
{
    /* --- Integer Data Types --- */
    char   letter   = 65;        /* 1 byte  | Range: -128 to 127 */
    int    number   = 32767;     /* 4 bytes | Range: -2147483648 to 2147483647 */
    short  small    = 100;       /* 2 bytes | Range: -32768 to 32767 */
    long   big      = 1000000L;  /* 4/8 bytes | Large numbers */

    /* --- Floating Point Types --- */
    float  pi_f  = 3.14f;        /* 4 bytes | Less precise */
    double pi_d  = 3.141593;     /* 8 bytes | More precise */

    /* --- Unsigned types (important in embedded!) --- */
    unsigned char  reg_val  = 255;   /* 0 to 255 - used for registers in MCU */
    unsigned int   port_val = 65535; /* 0 to 65535 */

    printf("--- Integer Types ---\n");
    printf("char value: %d (ASCII: %c)\n", letter, letter);
    printf("int value: %d\n", number);
    printf("short value: %d\n", small);
    printf("long value: %ld\n", big);

    printf("\n--- Float Types ---\n");
    printf("float: %.2f\n", pi_f);
    printf("double: %f\n", pi_d);

    printf("\n--- Unsigned Types (important in Embedded!) ---\n");
    printf("unsigned char (register): %u\n", reg_val);
    printf("unsigned int (port): %u\n", port_val);

    printf("\n--- Sizes in bytes ---\n");
    printf("Size of char: %lu bytes\n",   sizeof(char));
    printf("Size of int: %lu bytes\n",    sizeof(int));
    printf("Size of float: %lu bytes\n",  sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));

    return 0;
}
