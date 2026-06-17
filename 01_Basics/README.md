# 01 - Basics of C

Programs in this folder cover the very foundation of C programming.
I started here when I was new to C. Simple stuff but very important!

## Files

| File | Topic |
|------|-------|
| 01_hello_world.c | First program, printf |
| 02_variables_datatypes.c | Variables, data types, sizeof |
| 03_constants.c | #define vs const |
| 04_type_casting.c | Implicit and explicit casting |
| 05_input_output.c | scanf, printf, format specifiers |
| 06_storage_classes.c | auto, static, register, extern |

## Key Points for Interview

- **char** = 1 byte, **int** = 4 bytes, **float** = 4 bytes, **double** = 8 bytes
- In embedded, prefer **unsigned char** (uint8_t) for 8-bit MCU registers
- **#define** = no type checking, preprocessor level
- **const** = type-safe, compiler level
- **static local** variable retains value between function calls
- **volatile** prevents compiler optimization (NOT a storage class)

## Compile & Run

```bash
gcc 01_hello_world.c -o hello
./hello
```
