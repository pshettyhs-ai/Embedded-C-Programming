/*
 * Program  : Pointer Arithmetic
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * You can do arithmetic on pointers:
 * ptr+1 moves to the NEXT element (size depends on data type!)
 *
 * int*  : ptr+1 moves 4 bytes forward
 * char* : ptr+1 moves 1 byte forward
 *
 * Expected Output:
 * arr[0] at address 100: value = 10
 * arr[1] at address 104: value = 20
 * (addresses differ by 4 because int = 4 bytes)
 */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  /* ptr points to first element */
    int i;

    printf("--- Integer Pointer Arithmetic ---\n");
    for(i = 0; i < 5; i++)
    {
        printf("arr[%d] at %p: value = %d\n", i, ptr+i, *(ptr+i));
    }

    /* Moving pointer forward */
    printf("\n--- Moving pointer forward ---\n");
    ptr = arr;
    printf("*ptr     = %d (arr[0])\n", *ptr);
    ptr++;
    printf("*ptr     = %d (arr[1])\n", *ptr);
    ptr += 2;
    printf("*ptr     = %d (arr[3])\n", *ptr);

    /* char pointer moves 1 byte at a time */
    printf("\n--- Char Pointer Arithmetic ---\n");
    char msg[] = "Hello";
    char *cptr = msg;
    while(*cptr != '\0')
    {
        printf("Address: %p | Char: %c\n", cptr, *cptr);
        cptr++;  /* moves 1 byte */
    }

    /* Pointer subtraction: find distance between two pointers */
    int *p1 = &arr[1];
    int *p2 = &arr[4];
    printf("\nDistance between arr[1] and arr[4]: %ld elements\n", p2 - p1);

    return 0;
}
