# 11 - Bitwise Operators

**This is THE most important topic for embedded systems!**
Every register configuration on a microcontroller uses bitwise ops.
Master this and you'll stand out in interviews.

## Files

| File | Topic |
|------|-------|
| 01_bitwise_basics.c | AND, OR, XOR, NOT, shifts |
| 02_set_clear_toggle_bit.c | GPIO register operations |
| 03_check_bit.c | Reading bit status, masking |
| 04_bit_shifting.c | << and >> with register building |
| 05_swap_using_xor.c | XOR swap trick |
| 06_count_set_bits.c | Population count |
| 07_gpio_bit_manipulation.c | Full GPIO simulation |

## Critical Operations to Memorize

```c
reg |=  (1 << n);     // Set bit n
reg &= ~(1 << n);     // Clear bit n
reg ^=  (1 << n);     // Toggle bit n
bit = (reg >> n) & 1; // Read bit n
```

## Interview Notes
- XOR swap trick: `a^=b; b^=a; a^=b;`
- Power of 2 check: `n & (n-1) == 0`
- Brian Kernighan bit count: `n &= (n-1)` clears lowest set bit
- In STM32: `GPIOA->ODR |= GPIO_PIN_5;` — pure bitwise!
