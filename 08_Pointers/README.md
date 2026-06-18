# 08 - Pointers in C

Pointers are the most important topic in C for embedded systems!
Almost everything in embedded C uses pointers:
- Register access (memory-mapped I/O)
- Buffer passing to functions
- Callback / ISR function tables
- Dynamic memory

## Files

| File | Topic |
|------|-------|
| 01_pointer_basics.c | Declaration, &, *, NULL |
| 02_pointer_arithmetic.c | ptr++, ptr+n, subtraction |
| 03_pointer_and_arrays.c | arr[i] == *(arr+i) |
| 04_pointer_to_pointer.c | double pointer (**) |
| 05_function_pointers.c | Callbacks, state machines |
| 06_void_pointer.c | Generic pointer, memcpy |

## Interview Notes
- `*ptr` = dereference (get value at address)
- `&var` = address-of (get address of variable)
- `arr` and `&arr[0]` are the same
- `ptr + 1` moves by `sizeof(*ptr)` bytes
- Always initialize pointers! Dangling pointers cause hard bugs on MCUs
- `volatile int *ptr` = pointer to volatile int (for hardware registers!)
