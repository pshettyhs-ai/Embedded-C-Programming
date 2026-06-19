# 12 - Preprocessor Directives

The preprocessor runs BEFORE compilation.
It handles #include, #define, #ifdef etc.
This is very important for embedded C code organization.

## Files

| File | Topic |
|------|-------|
| 01_define_macro.c | #define constants, register addresses |
| 02_macro_functions.c | Function-like macros, bit macros |
| 03_conditional_compilation.c | #ifdef DEBUG, board selection |
| 04_header_guards.c | #ifndef HEADER_H guard pattern |
| 05_include_files.c | stdint.h, stdbool.h, string.h |

## Interview Notes
- `#define` is handled by preprocessor — no type checking!
- Always use parentheses in macro arguments: `#define SQ(x) ((x)*(x))`
- Header guards prevent multiple inclusion errors
- `uint8_t`, `uint16_t` come from `<stdint.h>`
- `DEBUG_PRINT` macro pattern: zero overhead in release builds
