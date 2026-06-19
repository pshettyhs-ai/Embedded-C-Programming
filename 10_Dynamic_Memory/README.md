# 10 - Dynamic Memory Allocation

Dynamic memory lets you allocate RAM at runtime.
Important concept for C interviews, though rarely used on small 8-bit MCUs.

## Files

| File | Topic |
|------|-------|
| 01_malloc_example.c | malloc - allocate uninitialized |
| 02_calloc_example.c | calloc - allocate + zero-init |
| 03_realloc_example.c | realloc - resize allocation |
| 04_free_memory.c | free, common bugs |
| 05_dynamic_array.c | Runtime-sized array |

## Interview Notes
- `malloc` returns `void*`, cast it to your type
- `calloc` zero-initializes; `malloc` does NOT
- ALWAYS check return value for `NULL`
- ALWAYS `free()` what you `malloc()`
- Set pointer to `NULL` after `free()` to avoid dangling pointer
- In embedded MCUs (Arduino, 8051): avoid dynamic memory — use static arrays!
