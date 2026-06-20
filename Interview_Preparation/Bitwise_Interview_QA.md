# Bitwise Operators Interview Q&A

**Prepared by:** PAVAN SHETTY H S  
**Topic:** Bitwise Operations — must-know for embedded interviews!

---

## Quick Reference

```c
// Set bit n
reg |=  (1 << n);

// Clear bit n
reg &= ~(1 << n);

// Toggle bit n
reg ^=  (1 << n);

// Read bit n
bit = (reg >> n) & 1;

// Set multiple bits
reg |= (1<<3) | (1<<5);

// Clear multiple bits
reg &= ~((1<<3) | (1<<5));

// Mask lower nibble
lower = val & 0x0F;

// Mask upper nibble
upper = (val >> 4) & 0x0F;
```

---

**Q1. What are the bitwise operators in C?**

| Operator | Name | Example |
|----------|------|---------|
| `&` | AND | `0xF0 & 0x3C = 0x30` |
| `\|` | OR | `0xF0 \| 0x0F = 0xFF` |
| `^` | XOR | `0xFF ^ 0x0F = 0xF0` |
| `~` | NOT (complement) | `~0x0F = 0xF0` (for 8-bit) |
| `<<` | Left shift | `1 << 3 = 8` |
| `>>` | Right shift | `16 >> 2 = 4` |

---

**Q2. How do you set, clear, and toggle bit 4 of variable `reg`?**

```c
// Set bit 4
reg |= (1 << 4);    // reg = reg | 0b00010000

// Clear bit 4
reg &= ~(1 << 4);   // reg = reg & 0b11101111

// Toggle bit 4
reg ^= (1 << 4);    // reg = reg ^ 0b00010000

// Read bit 4
int b4 = (reg >> 4) & 1;
```

---

**Q3. What is the output?**

```c
unsigned char a = 0x35;   // 0011 0101
unsigned char b = 0x5A;   // 0101 1010

printf("a & b = 0x%X\n", a & b);   // ?
printf("a | b = 0x%X\n", a | b);   // ?
printf("a ^ b = 0x%X\n", a ^ b);   // ?
printf("~a    = 0x%X\n", (unsigned char)~a); // ?
```

**Answer:**
```
a & b = 0x10   (0001 0000)
a | b = 0x7F   (0111 1111)
a ^ b = 0x6F   (0110 1111)
~a    = 0xCA   (1100 1010)
```

---

**Q4. How do you swap two numbers without a temporary variable using XOR?**

```c
int a = 5, b = 10;

a ^= b;   // a = a ^ b = 5 ^ 10 = 15  (0101 ^ 1010 = 1111)
b ^= a;   // b = b ^ a = 10 ^ 15 = 5  (now b has original a)
a ^= b;   // a = a ^ b = 15 ^ 5 = 10  (now a has original b)

// Result: a = 10, b = 5
```

> **Important:** This fails if `a` and `b` are the same variable (same memory address)!

---

**Q5. How do you check if a number is even or odd using bitwise operators?**

```c
int n = 7;
if (n & 1)
    printf("Odd\n");
else
    printf("Even\n");
```

Bit 0 is always 1 for odd numbers and 0 for even numbers.

---

**Q6. How do you check if a number is a power of 2?**

```c
int is_power_of_2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

**Why it works:** Powers of 2 have exactly one `1` bit.  
`n - 1` flips that bit and all lower bits.  
`n & (n-1)` clears the lowest set bit → result is 0 for powers of 2.

```
n  = 8  = 1000
n-1= 7  = 0111
n&(n-1) = 0000  → power of 2!

n  = 6  = 0110
n-1= 5  = 0101
n&(n-1) = 0100  → NOT power of 2
```

---

**Q7. Write a function to count the number of set bits (1s) in a number.**

**Method 1: Loop through all bits**
```c
int count_bits(unsigned int n) {
    int count = 0;
    while(n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
```

**Method 2: Brian Kernighan's trick (faster!)**
```c
int count_bits(unsigned int n) {
    int count = 0;
    while(n) {
        n &= (n - 1);  // clears the lowest set bit each time
        count++;
    }
    return count;
}
```

---

**Q8. What does left shift and right shift do in terms of arithmetic?**

```c
int x = 4;
x << 1  = 8;    // multiply by 2
x << 2  = 16;   // multiply by 4
x << 3  = 32;   // multiply by 8

int y = 32;
y >> 1  = 16;   // divide by 2
y >> 2  = 8;    // divide by 4
y >> 3  = 4;    // divide by 8
```

Shift is faster than multiplication/division — useful in embedded for fast math!

> **Warning:** Right shift on **signed** negative numbers is implementation-defined. Use unsigned for bit shifting in embedded.

---

**Q9. How do you extract the lower and upper nibble (4 bits) of a byte?**

```c
uint8_t data = 0xAB;   // 1010 1011

uint8_t lower_nibble = data & 0x0F;         // 0x0B = 0000 1011
uint8_t upper_nibble = (data >> 4) & 0x0F;  // 0x0A = 0000 1010

// Reassemble
uint8_t reassembled = (upper_nibble << 4) | lower_nibble;  // 0xAB
```

---

**Q10. How do you reverse the bits of a byte?**

```c
uint8_t reverse_bits(uint8_t n) {
    uint8_t result = 0;
    int i;
    for(i = 0; i < 8; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}
// reverse_bits(0b10110001) = 0b10001101
```

---

**Q11. Practical: Configure GPIO pin 5 as output using register.**

```c
// STM32 GPIOA_MODER: 2 bits per pin
// 00 = input, 01 = output, 10 = alternate, 11 = analog

volatile uint32_t *GPIOA_MODER = (uint32_t*)0x40020000;

// Configure PA5 as output (bits 11:10 = 01)
*GPIOA_MODER &= ~(0x3U << (5 * 2));   // clear bits 11:10
*GPIOA_MODER |=  (0x1U << (5 * 2));   // set bits 11:10 = 01 (output)

// Set PA5 HIGH (turn on LED)
volatile uint32_t *GPIOA_ODR = (uint32_t*)0x40020014;
*GPIOA_ODR |= (1U << 5);

// Clear PA5 LOW (turn off LED)
*GPIOA_ODR &= ~(1U << 5);
```

---

**Q12. What is masking? Give an example.**

Masking uses AND to keep only certain bits and zero out the rest.

```c
uint8_t byte = 0b10110111;

// Keep only bits [3:0] (lower nibble)
uint8_t masked = byte & 0x0F;   // 0b00000111

// Keep only bits [7:4] (upper nibble)
uint8_t upper  = byte & 0xF0;   // 0b10110000

// Practical: extract UART stop bits (bits [3:2]) from config register
uint8_t config = 0xA8;           // 1010 1000
uint8_t stop_bits = (config >> 2) & 0x03;  // extract bits [3:2]
```

---

**Q13. Find the position of the highest set bit (MSB position).**

```c
int highest_set_bit(unsigned int n) {
    int pos = -1;
    while(n) {
        pos++;
        n >>= 1;
    }
    return pos;
}
// highest_set_bit(0b00101000) = 5
```

---

**Q14. How do you multiply and divide by powers of 2 efficiently?**

```c
int x = 5;

// Multiply by 8 (= 2^3)
int result = x << 3;   // 40  — faster than x * 8

// Divide by 4 (= 2^2)
int result2 = x << 1;  // first multiply to make 10
int div = 40 >> 2;     // 10  — faster than 40 / 4
```

This optimization is automatically applied by compilers with optimization flags (`-O1`, `-O2`).

---

## Common Bit Manipulation Macros to Memorize

```c
#define SET_BIT(reg, n)      ((reg) |=  (1U << (n)))
#define CLEAR_BIT(reg, n)    ((reg) &= ~(1U << (n)))
#define TOGGLE_BIT(reg, n)   ((reg) ^=  (1U << (n)))
#define READ_BIT(reg, n)     (((reg) >> (n)) & 1U)
#define IS_SET(reg, n)       (((reg) >> (n)) & 1U)

// Multiple bits
#define SET_BITS(reg, mask)   ((reg) |=  (mask))
#define CLEAR_BITS(reg, mask) ((reg) &= ~(mask))

// Field extraction (n-bit field at position pos)
#define GET_FIELD(reg, pos, len) \
    (((reg) >> (pos)) & ((1U << (len)) - 1))
```

---

*Pavan's tip: Before any embedded interview, practice: set bit 5 of register 0x2A without affecting other bits. You should be able to write that in under 5 seconds!*
