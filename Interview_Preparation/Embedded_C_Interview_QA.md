# Embedded C Interview Questions & Answers

**Prepared by:** PAVAN SHETTY H S  
**Branch:** Electronics and Communication Engineering  
**Purpose:** Interview preparation for Embedded Software Engineer roles

---

## 1. C Language Fundamentals

---

**Q1. What is the difference between `#define` and `const`?**

| Feature | `#define` | `const` |
|---------|-----------|---------|
| Handled by | Preprocessor | Compiler |
| Type checking | No | Yes |
| Memory | No memory (text substitution) | Occupies memory |
| Debugging | Harder | Easier |
| Scope | Global (from point of definition) | Follows scope rules |

```c
#define MAX_SIZE 100        // no type, no memory
const int MAX_SIZE = 100;   // typed, occupies memory
```

In embedded C, `#define` is preferred for register addresses and pin numbers because there's no memory overhead.

---

**Q2. What is the `volatile` keyword? Why is it critical in embedded C?**

`volatile` tells the compiler: *"Do not optimize reads/writes to this variable — always read it fresh from memory."*

**Without `volatile`, the compiler may:**
- Cache the variable in a CPU register
- Optimize away repeated reads
- Reorder memory accesses

**Use `volatile` for:**
- Hardware registers (GPIO, UART, SPI, ADC)
- Variables modified by ISR (Interrupt Service Routines)
- Variables shared between RTOS tasks
- Variables modified by DMA

```c
// WRONG: compiler may optimize to: while(1){}
int flag = 0;
while(flag == 0);

// CORRECT: compiler always reads from memory
volatile int flag = 0;
while(flag == 0);

// Hardware register MUST be volatile
volatile uint32_t *GPIOA_IDR = (volatile uint32_t*)0x40020010;
```

---

**Q3. What is the difference between `const int *p`, `int * const p`, and `const int * const p`?**

```c
const int *p;        // pointer to const int — can change pointer, not value
int * const p;       // const pointer to int — cannot change pointer, can change value
const int * const p; // const pointer to const int — cannot change either
```

Memory trick: *read from right to left*
- `const int *p`     → p is a pointer to (const int)
- `int * const p`    → p is a (const pointer) to int

**In embedded:**
```c
volatile const uint32_t *GPIO_IDR; // read-only hardware register
```

---

**Q4. What are storage classes in C?**

| Storage Class | Lifetime | Scope | Default Value |
|---------------|----------|-------|---------------|
| `auto` | Function block | Local | Garbage |
| `register` | Function block | Local | Garbage |
| `static` (local) | Program | Local | Zero |
| `static` (global) | Program | File | Zero |
| `extern` | Program | Multiple files | Zero |

**Key embedded use — static local variable:**
```c
void count_interrupts(void) {
    static uint32_t count = 0;  // retains value between calls!
    count++;
}
```

**register:**
```c
register int i;  // hint: store in CPU register for faster loop
for(i = 0; i < 1000; i++) { ... }
```

---

**Q5. What is the difference between `struct` and `union`?**

| Feature | `struct` | `union` |
|---------|----------|---------|
| Memory | Sum of all members (+ padding) | Size of largest member |
| Members | Each has own memory | All share same memory |
| Valid members | All at same time | Only one at a time |

```c
struct S { int a; char b; };   // sizeof = 8 (with padding)
union  U { int a; char b; };   // sizeof = 4 (int is largest)
```

**Union practical use — status register bit fields:**
```c
union UART_Status {
    uint8_t all;
    struct {
        uint8_t rx_ready  : 1;
        uint8_t tx_empty  : 1;
        uint8_t parity_err: 1;
        uint8_t reserved  : 5;
    } bits;
};
```

---

## 2. Pointers

---

**Q6. What is a dangling pointer?**

A dangling pointer points to memory that has already been freed or gone out of scope.

```c
int *p = (int*)malloc(sizeof(int));
free(p);
*p = 10;  // DANGLING POINTER! undefined behavior, crash on MCU!

// Fix: always NULL after free
free(p);
p = NULL;
```

---

**Q7. What is the difference between `NULL` pointer and a void pointer?**

- **NULL pointer:** A pointer that points to address 0 (nothing). Used to show a pointer is invalid/uninitialized.
- **void pointer:** A generic pointer that can hold the address of any type. Must be cast before dereferencing.

```c
int *p = NULL;           // NULL pointer - points to nothing
void *vp = &some_var;   // void pointer - generic, holds any address
int *ip = (int*)vp;     // must cast to use
```

---

**Q8. What is a function pointer? Give an embedded use case.**

A function pointer stores the address of a function, enabling you to call different functions dynamically.

```c
// Declaration: return_type (*ptr_name)(param_types)
void (*isr_handler)(void);

void timer_isr(void) { /* handle timer */ }
void uart_isr(void)  { /* handle uart  */ }

// Assign
isr_handler = timer_isr;
isr_handler();  // calls timer_isr

// Embedded use: ISR vector table / callback registration
typedef void (*ISR_Callback)(void);
ISR_Callback isr_table[10];
isr_table[0] = timer_isr;
isr_table[1] = uart_isr;
```

---

## 3. Interrupts

---

**Q9. What is an ISR? What should and should NOT be done inside an ISR?**

An ISR (Interrupt Service Routine) is a function called automatically by hardware when an interrupt event occurs.

**DO inside ISR:**
- Set a `volatile` flag for main loop to handle
- Copy received data to a buffer
- Clear the interrupt flag/register
- Keep it SHORT (microseconds at most)

**DO NOT inside ISR:**
- `printf()` — uses UART which may block
- `malloc()` / `free()` — not thread-safe, slow
- Long loops or delays
- Call functions that disable/enable interrupts themselves

```c
volatile uint8_t uart_rx_flag = 0;
volatile uint8_t uart_rx_data = 0;

void UART_RX_ISR(void) {
    uart_rx_data = UART_DATA_REG;  // copy data
    uart_rx_flag = 1;               // set flag for main
    // clear interrupt flag in hardware register
}

// Main loop
while(1) {
    if(uart_rx_flag) {
        uart_rx_flag = 0;
        process_data(uart_rx_data);  // process outside ISR
    }
}
```

---

**Q10. What is a critical section?**

A critical section is a block of code where shared data is accessed, and interrupts must be disabled to prevent race conditions.

```c
// Without protection — RACE CONDITION possible!
shared_counter++;

// With critical section — safe
__disable_irq();     // disable all interrupts
shared_counter++;    // atomic operation now
__enable_irq();      // re-enable interrupts
```

---

## 4. Memory

---

**Q11. What are the different memory segments in C?**

| Segment | Contains | Characteristics |
|---------|----------|-----------------|
| **Text / Code** | Program instructions | Read-only, in Flash |
| **BSS** | Uninitialized global/static vars | Zero-initialized at startup |
| **Data** | Initialized global/static vars | Copied from Flash to RAM |
| **Stack** | Local variables, function calls | LIFO, fixed size |
| **Heap** | Dynamic memory (`malloc`) | Grows upward |

**In embedded (e.g., STM32):**
- Flash = Text + Data initial values
- RAM = BSS + Data (runtime) + Stack + Heap

---

**Q12. What is stack overflow and how does it happen on MCUs?**

Stack overflow occurs when the stack grows beyond its allocated size, corrupting other memory.

**Causes:**
- Deep recursion
- Large local arrays inside functions
- Deeply nested function calls in ISRs

**Prevention:**
- Avoid recursion in embedded
- Use static/global arrays for large buffers
- Use stack monitoring (watermarking) in RTOS

```c
// BAD: 1000 bytes on stack inside an ISR
void ISR_Handler(void) {
    char buffer[1000];  // dangerous!
}

// GOOD: static = goes to BSS, not stack
void ISR_Handler(void) {
    static char buffer[1000];  // safe
}
```

---

**Q13. What is the difference between `malloc` and `calloc`?**

| Function | Initialization | Usage |
|----------|----------------|-------|
| `malloc(size)` | No initialization (garbage) | Single block |
| `calloc(n, size)` | Zero-initialized | Array of n elements |
| `realloc(ptr, size)` | Preserves old data | Resize allocation |

```c
int *a = malloc(10 * sizeof(int));   // allocate, garbage values
int *b = calloc(10, sizeof(int));    // allocate, all zeros
```

> **Note for embedded:** Avoid dynamic memory on small MCUs. Use static arrays instead. Dynamic memory causes fragmentation and heap exhaustion.

---

## 5. Communication Protocols

---

**Q14. Compare UART, SPI, and I2C.**

| Feature | UART | SPI | I2C |
|---------|------|-----|-----|
| Wires | 2 (TX, RX) | 4 (MOSI, MISO, SCK, SS) | 2 (SDA, SCL) |
| Type | Asynchronous | Synchronous | Synchronous |
| Speed | Up to ~1 Mbps | Up to 80 MHz | 100kHz–1MHz |
| Duplex | Full | Full | Half |
| Slaves | Point-to-point | Multiple (1 SS/slave) | Multiple (address-based) |
| Pull-ups | No | No | Yes (4.7kΩ required) |

---

**Q15. What is baud rate? How do you calculate UART UBRR?**

Baud rate = number of symbol changes per second (bits per second for UART).

```
UBRR = (F_CPU / (16 × BAUD_RATE)) - 1
```

Example for 9600 baud at 16 MHz:
```
UBRR = (16,000,000 / (16 × 9600)) - 1 = 103
```

---

**Q16. What is the difference between I2C ACK and NACK?**

- **ACK (Acknowledge):** Receiver pulls SDA LOW during the 9th clock pulse — "I got the byte, send more"
- **NACK (Not Acknowledge):** SDA stays HIGH — "stop sending" or "error"

NACK is sent by the master after the LAST byte it wants to read, to tell the slave the read is complete.

---

## 6. Miscellaneous

---

**Q17. What is endianness?**

Endianness describes byte order for multi-byte values in memory.

- **Big-endian:** Most significant byte at lowest address (network order)
- **Little-endian:** Least significant byte at lowest address (x86, ARM by default)

```c
uint32_t val = 0x12345678;
// Little-endian memory: [0x78][0x56][0x34][0x12]
// Big-endian memory:    [0x12][0x34][0x56][0x78]

// Check endianness at runtime:
uint16_t x = 1;
char *p = (char*)&x;
printf(*p == 1 ? "Little-endian\n" : "Big-endian\n");
```

---

**Q18. What is a circular buffer (ring buffer) and why is it used?**

A circular buffer uses a fixed-size array with head and tail indices that wrap around.

```c
#define BUF_SIZE 64
uint8_t buf[BUF_SIZE];
int head = 0, tail = 0;

void enqueue(uint8_t data) {
    buf[head] = data;
    head = (head + 1) % BUF_SIZE;  // wrap around
}

uint8_t dequeue(void) {
    uint8_t data = buf[tail];
    tail = (tail + 1) % BUF_SIZE;
    return data;
}
```

**Why used in embedded:**
- UART RX ISR writes to buffer (fast)
- Main loop reads from buffer (slow processing OK)
- No data lost if main is temporarily busy

---

**Q19. What is DMA? Why is it useful?**

DMA (Direct Memory Access) allows peripherals to transfer data directly to/from RAM without CPU involvement.

**Benefits:**
- CPU is free to do other work during transfer
- Faster transfers (no interrupt overhead per byte)
- Critical for high-speed ADC, audio, image data

**Example:** DMA-based UART
- Without DMA: interrupt per byte → CPU overhead
- With DMA: entire buffer transferred, one interrupt when done

---

**Q20. What is RTOS? What is the difference between a task and an ISR?**

An RTOS (Real-Time Operating System) like FreeRTOS manages multiple tasks with timing guarantees.

| Feature | Task | ISR |
|---------|------|-----|
| Called by | Scheduler | Hardware interrupt |
| Can block | Yes (wait, delay) | Never |
| Priority | Software-defined | Hardware-defined |
| Stack | Own stack | ISR stack |
| Can use malloc | Yes (with care) | No |

---

*Last updated by PAVAN SHETTY H S — keep revising before every interview!*
