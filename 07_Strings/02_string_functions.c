/*
 * Program  : Standard String Functions
 * Author   : PAVAN SHETTY H S
 * Topic    : Strings
 *
 * Important string.h functions:
 * strlen()  - length of string
 * strcpy()  - copy string
 * strcat()  - concatenate (join) strings
 * strcmp()  - compare strings
 * strchr()  - find a character
 * strstr()  - find a substring
 *
 * Expected Output:
 * (various string operation results)
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100] = "Hello";
    char s2[]    = " World";
    char s3[100];

    /* strlen - length (does NOT include '\0') */
    printf("strlen(\"%s\") = %lu\n", s1, strlen(s1));

    /* strcpy - copy s1 into s3 */
    strcpy(s3, s1);
    printf("strcpy: s3 = \"%s\"\n", s3);

    /* strcat - append s2 to s1 */
    strcat(s1, s2);
    printf("strcat: s1 = \"%s\"\n", s1);

    /* strcmp - compare strings (returns 0 if equal) */
    char pass1[] = "admin123";
    char pass2[] = "admin123";
    char pass3[] = "wrongpass";

    if(strcmp(pass1, pass2) == 0)
        printf("\nstrcmp: \"%s\" == \"%s\" -> MATCH\n", pass1, pass2);

    if(strcmp(pass1, pass3) != 0)
        printf("strcmp: \"%s\" != \"%s\" -> NO MATCH\n", pass1, pass3);

    /* strchr - find first occurrence of a character */
    char sentence[] = "Embedded C is great!";
    char *pos = strchr(sentence, 'C');
    if(pos)
        printf("\nstrchr: Found 'C' at position %ld\n", pos - sentence);

    /* strstr - find a substring */
    char *found = strstr(sentence, "great");
    if(found)
        printf("strstr: Found \"great\" at position %ld\n", found - sentence);

    /* strtok - split string by delimiter (useful for UART commands!) */
    printf("\nstrtok example (split by comma):\n");
    char data[] = "Pavan,ECE,Embedded,2024";
    char *token = strtok(data, ",");
    while(token != NULL)
    {
        printf("  Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
