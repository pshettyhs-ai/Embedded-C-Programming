# 14 - GPIO Examples

GPIO (General Purpose Input/Output) is the most basic
peripheral on any microcontroller. Everything starts here!

## Files

| File | Topic |
|------|-------|
| 01_led_blink.c | LED blink (STM32 register style) |
| 02_led_button_control.c | Button input + LED output + debounce |
| 03_multiple_leds.c | 8 LEDs, patterns, Knight Rider effect |
| 04_led_patterns.c | Pattern lookup tables, binary counter |
| 05_gpio_register_access.c | AVR (ATmega328P) DDR/PORT/PIN registers |

## Quick Reference: GPIO Operations

### AVR (ATmega)
```c
DDRB  |=  (1 << 5);   // PB5 = OUTPUT
PORTB |=  (1 << 5);   // PB5 = HIGH
PORTB &= ~(1 << 5);   // PB5 = LOW
PORTB ^=  (1 << 5);   // PB5 = TOGGLE
bit = (PINB >> 5) & 1; // read PB5
```

### STM32 (HAL)
```c
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
```
