/*
 * Program  : void Pointer in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Pointers
 *
 * void* is a generic pointer - can point to any data type.
 * Must be cast to specific type before dereferencing.
 * Used in: generic functions like memcpy(), malloc(), etc.
 *
 * Expected Output:
 * Integer via void*: 42
 * Float via void*:   3.14
 */

#include <stdio.h>
#include <string.h>

/* Generic print function using void pointer */
void generic_print(void *ptr, char type)
{
    switch(type)
    {
        case 'i': printf("Integer: %d\n",  *(int*)ptr);   break;
        case 'f': printf("Float:   %.2f\n",*(float*)ptr); break;
        case 'c': printf("Char:    %c\n",  *(char*)ptr);  break;
        default:  printf("Unknown type\n");                break;
    }
}

/* Manual memcpy using void pointers */
void my_memcpy(void *dest, const void *src, int size)
{
    char *d = (char*)dest;
    const char *s = (const char*)src;
    int i;
    for(i = 0; i < size; i++)
        d[i] = s[i];
}

int main()
{
    int   a = 42;
    float b = 3.14f;
    char  c = 'P';

    void *vptr;

    vptr = &a; generic_print(vptr, 'i');
    vptr = &b; generic_print(vptr, 'f');
    vptr = &c; generic_print(vptr, 'c');

    /* my_memcpy demo */
    char src[] = "Embedded C";
    char dst[20];
    my_memcpy(dst, src, strlen(src)+1);
    printf("\nCopied string: %s\n", dst);

    /* Embedded: memset to clear a buffer */
    unsigned char buf[8];
    memset(buf, 0xFF, sizeof(buf));
    printf("Buffer filled with 0xFF: ");
    int i;
    for(i = 0; i < 8; i++) printf("0x%02X ", buf[i]);
    printf("\n");

    return 0;
}
