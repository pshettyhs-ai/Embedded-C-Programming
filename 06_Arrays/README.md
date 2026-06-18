# 06 - Arrays in C

Arrays are fundamental in embedded systems.
UART receive buffers, ADC sample buffers, lookup tables — all use arrays!

## Files

| File | Topic |
|------|-------|
| 01_1D_array.c | 1D array basics + ADC buffer |
| 02_2D_array.c | Matrix + keypad layout |
| 03_array_operations.c | Insert, delete, reverse |
| 04_array_sorting.c | Bubble sort, Selection sort |
| 05_array_search.c | Linear search, Binary search |
| 06_array_and_functions.c | Passing arrays + circular buffer |

## Interview Notes
- Array index starts at 0
- Array name is a pointer to the first element
- Arrays passed to functions can be modified (no copy is made)
- Binary search needs SORTED array
- **Circular buffer** is very common in UART/SPI drivers!
