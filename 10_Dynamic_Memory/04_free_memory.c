/*
 * Program  : Memory Management and Common Mistakes
 * Author   : PAVAN SHETTY H S
 * Topic    : Dynamic Memory Allocation
 *
 * Common memory bugs (very important for embedded interviews!):
 * 1. Memory Leak    - allocate but never free
 * 2. Dangling Pointer - use after free
 * 3. Double Free    - free same pointer twice (crash!)
 * 4. Buffer Overflow- write beyond allocated size
 *
 * Expected Output:
 * Good memory management demo
 */

#include <stdio.h>
#include <stdlib.h>

/* BAD: Memory leak - memory never freed */
void bad_function_leak()
{
    int *ptr = (int*) malloc(100 * sizeof(int));
    /* ... use ptr ... */
    /* forgot to free! memory is now lost (leaked) */
    printf("BAD: Memory leaked - forgot to free!\n");
}

/* GOOD: Properly freed */
void good_function()
{
    int *ptr = (int*) malloc(100 * sizeof(int));
    if(!ptr) return;
    /* ... use ptr ... */
    free(ptr);       /* release memory */
    ptr = NULL;      /* avoid dangling pointer */
    printf("GOOD: Memory allocated and properly freed.\n");
}

int main()
{
    printf("=== Memory Management Best Practices ===\n\n");

    bad_function_leak();
    good_function();

    printf("\n--- Rules to remember ---\n");
    printf("1. Every malloc/calloc must have a matching free()\n");
    printf("2. Always check if malloc returned NULL\n");
    printf("3. Set pointer to NULL after free()\n");
    printf("4. Never free a pointer twice\n");
    printf("5. Never use a pointer after freeing it\n");

    /* Simulating a proper allocation/use/free cycle */
    printf("\n--- Proper cycle ---\n");
    int size = 10;
    int *buf = (int*) malloc(size * sizeof(int));
    if(buf == NULL) { printf("Allocation failed!\n"); return 1; }
    printf("Allocated %d bytes\n", (int)(size * sizeof(int)));

    int i;
    for(i = 0; i < size; i++) buf[i] = i * i;
    printf("Buffer: ");
    for(i = 0; i < size; i++) printf("%d ", buf[i]);
    printf("\n");

    free(buf);
    buf = NULL;
    printf("Memory freed. buf set to NULL.\n");
    printf("buf is now: %s\n", buf == NULL ? "NULL (safe!)" : "non-NULL");

    return 0;
}
