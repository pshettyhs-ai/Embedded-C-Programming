/*
 * Program  : Check if a String is a Palindrome
 * Author   : PAVAN SHETTY H S
 * Topic    : Strings
 *
 * A palindrome reads the same forwards and backwards.
 * Example: "madam", "racecar", "level"
 *
 * Expected Output:
 * "madam" is a Palindrome
 * "hello" is NOT a Palindrome
 */

#include <stdio.h>
#include <string.h>

int is_palindrome(char *str)
{
    int left  = 0;
    int right = strlen(str) - 1;

    while(left < right)
    {
        if(str[left] != str[right])
            return 0;  /* not a palindrome */
        left++;
        right--;
    }
    return 1;  /* is a palindrome */
}

int main()
{
    char words[][20] = {"madam", "racecar", "hello", "level", "embedded", "noon"};
    int count = 6;
    int i;

    for(i = 0; i < count; i++)
    {
        if(is_palindrome(words[i]))
            printf("\"%s\" IS a palindrome\n", words[i]);
        else
            printf("\"%s\" is NOT a palindrome\n", words[i]);
    }

    return 0;
}
