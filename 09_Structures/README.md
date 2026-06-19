# 09 - Structures in C

Structures (and unions) are everywhere in embedded C.
MCU vendor header files use structs for peripheral registers.
e.g., STM32: `GPIOA->ODR |= GPIO_PIN_5;`

## Files

| File | Topic |
|------|-------|
| 01_struct_basics.c | Defining and using structs |
| 02_struct_array.c | Array of structs + GPIO table |
| 03_struct_pointer.c | -> operator, pass by pointer |
| 04_nested_struct.c | Struct inside struct (MCU config) |
| 05_union_basics.c | Union, shared memory, bit fields |
| 06_typedef.c | typedef, uint8_t, function pointers |

## Interview Notes
- Use `.` for direct access, `->` for pointer access
- Union size = size of largest member
- typedef creates aliases — `uint8_t` is just `unsigned char`
- Bit fields in union are heavily used for MCU register definitions
