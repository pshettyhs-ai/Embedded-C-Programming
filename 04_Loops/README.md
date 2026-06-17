# 04 - Loops in C

Loops are used everywhere in embedded systems:
- Polling for UART data
- Blinking LEDs
- Scanning keypads
- Delay functions (software delay)

## Files

| File | Topic |
|------|-------|
| 01_for_loop.c | for loop basics + bit printing |
| 02_while_loop.c | while loop + polling example |
| 03_do_while_loop.c | do-while loop + menu |
| 04_nested_loops.c | Nested loops + multiplication table |
| 05_break_continue.c | break and continue |
| 06_pattern_printing.c | Star patterns for interview practice |

## Interview Notes
- **for** = use when iterations are known
- **while** = use when condition is checked before (could be 0 iterations)
- **do-while** = use when at least 1 execution is needed
- In embedded, `while(1)` is the **infinite main loop** — the heart of every firmware!
