/*
 * Program  : Input and Output in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Basics of C
 *
 * Description:
 * Basic scanf and printf usage.
 * In real embedded systems, UART is used instead of stdin/stdout.
 *
 * Expected Output:
 * Enter your name: Pavan
 * Enter your age: 21
 * Hello, Pavan! You are 21 years old.
 */

#include <stdio.h>

int main()
{
    char name[50];
    int  age;
    float gpa;

    printf("Enter your name: ");
    scanf("%s", name);         /* %s reads a word (no spaces) */

    printf("Enter your age: ");
    scanf("%d", &age);         /* & is the address operator - very important! */

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("\n--- Your Details ---\n");
    printf("Hello, %s!\n", name);
    printf("Age: %d years\n", age);
    printf("GPA: %.2f\n", gpa);

    /* Format specifiers reminder:
     * %d  = integer
     * %f  = float
     * %c  = character
     * %s  = string
     * %ld = long integer
     * %u  = unsigned integer
     * %x  = hexadecimal (useful for register values!)
     * %o  = octal
     * %b  = binary (not standard, use custom function)
     */

    printf("\nHexadecimal of %d is: 0x%X\n", age, age);
    printf("Octal of %d is: %o\n", age, age);

    return 0;
}
