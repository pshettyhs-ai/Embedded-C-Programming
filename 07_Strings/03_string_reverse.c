/*
 * Program  : Reverse a String
 * Author   : PAVAN SHETTY H S
 * Topic    : Strings
 *
 * Two methods: using extra array, in-place using two pointers.
 *
 * Expected Output:
 * Original : Embedded
 * Reversed : deddebmE
 */

#include <stdio.h>
#include <string.h>

/* Method 1: Reverse into a new array */
void reverse_new(char *src, char *dest)
{
    int len = strlen(src);
    int i;
    for(i = 0; i < len; i++)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

/* Method 2: In-place reverse (no extra memory - better for embedded!) */
void reverse_inplace(char *str)
{
    int left  = 0;
    int right = strlen(str) - 1;
    char temp;

    while(left < right)
    {
        temp       = str[left];
        str[left]  = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    char original[] = "Embedded";
    char reversed[20];

    printf("Original : %s\n", original);

    reverse_new(original, reversed);
    printf("Reversed (new array): %s\n", reversed);

    reverse_inplace(original);
    printf("Reversed (in-place):  %s\n", original);

    /* Test with name */
    char name[] = "PAVAN SHETTY H S";
    printf("\nOriginal name: %s\n", name);
    reverse_inplace(name);
    printf("Reversed name: %s\n", name);

    return 0;
}
