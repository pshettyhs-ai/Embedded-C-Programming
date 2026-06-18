# 05 - Functions in C

Functions are the building blocks of any C program.
In embedded C, almost everything is organized as functions:
gpio_init(), uart_send(), adc_read(), isr_handler() etc.

## Files

| File | Topic |
|------|-------|
| 01_function_basics.c | Basics, prototypes, return types |
| 02_call_by_value.c | Passing by copy |
| 03_call_by_reference.c | Passing by pointer |
| 04_recursion.c | Recursive functions |
| 05_inline_functions.c | inline + macros for speed |

## Interview Notes
- **Call by value** = copy, original unchanged
- **Call by reference** = pointer, original changed
- **inline** = no function call overhead, faster
- **Recursion** — avoid in embedded! Limited stack on MCUs
- Always use function prototypes to avoid compiler warnings
