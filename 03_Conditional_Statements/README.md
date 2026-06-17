# 03 - Conditional Statements

Decision making is the heart of embedded programming.
A microcontroller is always making decisions: Is the button pressed? Is temperature too high?

## Files

| File | Topic |
|------|-------|
| 01_if_else.c | Basic if-else |
| 02_if_else_ladder.c | Multiple conditions (voltage/temp check) |
| 03_nested_if.c | if inside if (security system example) |
| 04_switch_case.c | switch-case with calculator + LED modes |
| 05_grade_calculator.c | Combined conditions |

## Interview Notes
- `switch` works only with integer/char constants — not float or string
- Forgetting `break` causes **fall-through** — a common bug!
- In embedded state machines, switch-case is the preferred pattern
