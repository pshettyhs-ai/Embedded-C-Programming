/*
 * Program  : String Operations - Count, Upper/Lower, Remove Spaces
 * Author   : PAVAN SHETTY H S
 * Topic    : Strings
 *
 * Expected Output:
 * Uppercase: PAVAN SHETTY H S
 * Lowercase: pavan shetty h s
 * Vowel count: 4
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_uppercase(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

void to_lowercase(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int count_vowels(char *str)
{
    int count = 0, i;
    for(i = 0; str[i] != '\0'; i++)
    {
        char c = tolower(str[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            count++;
    }
    return count;
}

int count_words(char *str)
{
    int count = 0, i, in_word = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && !in_word) { count++; in_word = 1; }
        else if(str[i] == ' ')          in_word = 0;
    }
    return count;
}

int main()
{
    char name[] = "Pavan Shetty H S";
    char sentence[] = "Embedded C Programming is fun";

    printf("Original:  %s\n", name);

    char tmp1[50], tmp2[50];
    strcpy(tmp1, name); to_uppercase(tmp1);
    strcpy(tmp2, name); to_lowercase(tmp2);

    printf("Uppercase: %s\n", tmp1);
    printf("Lowercase: %s\n", tmp2);

    printf("\nVowels in \"%s\": %d\n", sentence, count_vowels(sentence));
    printf("Words  in \"%s\": %d\n", sentence, count_words(sentence));

    /* Embedded: Parse a simple AT command */
    printf("\n--- AT Command Parser ---\n");
    char at_cmd[] = "AT+BAUD=9600";
    if(strstr(at_cmd, "AT+BAUD="))
    {
        char *val = strchr(at_cmd, '=') + 1;
        int baud  = atoi(val);
        printf("Parsed BAUD RATE = %d\n", baud);
    }

    return 0;
}
