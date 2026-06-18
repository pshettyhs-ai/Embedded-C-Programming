/*
 * Program  : String Basics in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Strings
 *
 * A string in C is a character array ending with '\0' (null terminator).
 * In embedded: used for UART messages, LCD display text, debug logs.
 *
 * Expected Output:
 * String: Hello, Embedded World!
 * Length: 22
 * First char: H
 */

#include <stdio.h>
#include <string.h>

int main()
{
    /* String declaration methods */
    char str1[] = "Hello, Embedded World!";   /* size auto-calculated */
    char str2[50] = "PAVAN SHETTY H S";       /* fixed size buffer */
    char str3[10];                             /* uninitialized */

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("Length of str1: %lu\n", strlen(str1));   /* does NOT count '\0' */
    printf("Size of str1 array: %lu\n", sizeof(str1)); /* includes '\0' */

    /* Character-by-character access */
    printf("\nCharacters of str2:\n");
    int i;
    for(i = 0; str2[i] != '\0'; i++)
        printf("[%d]='%c' ", i, str2[i]);
    printf("\n");

    /* Manual string copy */
    printf("\nManual copy of str1 into str3 (first 9 chars):\n");
    for(i = 0; i < 9 && str1[i] != '\0'; i++)
        str3[i] = str1[i];
    str3[i] = '\0';  /* ALWAYS null-terminate manually copied strings! */
    printf("str3: %s\n", str3);

    /* Embedded: UART message buffer */
    char uart_msg[64];
    sprintf(uart_msg, "Temp=%dC Volt=%.2fV\n", 45, 3.28f);
    printf("\nUART Message: %s", uart_msg);

    return 0;
}
