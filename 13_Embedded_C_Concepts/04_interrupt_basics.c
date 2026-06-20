/*
 * Program  : Interrupt Basics in Embedded C (Conceptual)
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * An interrupt temporarily stops the main program to handle
 * an urgent event (button press, timer overflow, UART data received).
 *
 * Key concepts:
 * - ISR (Interrupt Service Routine) = the handler function
 * - ISR should be FAST and SHORT
 * - Use volatile for variables shared between ISR and main
 * - Disable global interrupts when accessing shared data (critical section)
 *
 * This file shows the PATTERN used in real MCU code.
 * (Cannot compile actual interrupts without MCU hardware/simulator)
 *
 * Expected Output:
 * Interrupt concepts and patterns
 */

#include <stdio.h>
#include <stdint.h>

/* ===== Shared variables - MUST be volatile! ===== */
volatile uint8_t  timer_flag    = 0;   /* set by Timer ISR */
volatile uint8_t  rx_ready      = 0;   /* set by UART ISR */
volatile uint8_t  rx_byte       = 0;   /* data from UART ISR */
volatile uint32_t tick_count    = 0;   /* incremented every 1ms */
volatile uint8_t  button_flag   = 0;   /* set by EXTI (GPIO) ISR */

/* ===== ISR Handlers (in real MCU: defined in startup file) ===== */
/* These would be called automatically by hardware */

/* Timer ISR: fires every 1ms */
void TIM2_IRQHandler(void)
{
    tick_count++;                /* increment system tick */
    if(tick_count % 500 == 0)  /* every 500ms */
        timer_flag = 1;          /* signal main loop */
    /* Clear timer interrupt flag (in real MCU: TIM2->SR &= ~TIM_SR_UIF) */
}

/* UART Receive ISR */
void USART1_IRQHandler(void)
{
    /* rx_byte = USART1->DR;  // read from real UART data register */
    rx_byte  = 'H';  /* simulated received byte */
    rx_ready = 1;    /* signal main loop */
}

/* External GPIO interrupt (button press) */
void EXTI0_IRQHandler(void)
{
    button_flag = 1;
    /* Debounce: usually reset a timer here */
}

/* ===== Simulated critical section ===== */
/* In real MCU:
 * __disable_irq();  // disable all interrupts
 * ... access shared variable ...
 * __enable_irq();   // re-enable interrupts
 */
void disable_interrupts(void) { /* __disable_irq() */ }
void enable_interrupts(void)  { /* __enable_irq()  */ }

int main()
{
    printf("=== Interrupt Concepts in Embedded C ===\n\n");

    printf("1. ISR should be SHORT and FAST\n");
    printf("   - Set a flag, copy data, then return\n");
    printf("   - Never use printf() inside ISR!\n");
    printf("   - Never use long loops in ISR!\n\n");

    printf("2. Always use 'volatile' for ISR-shared variables\n");
    printf("   volatile uint8_t rx_ready = 0;\n\n");

    printf("3. Critical section pattern:\n");
    printf("   __disable_irq();\n");
    printf("   shared_variable++;  // safe, no interrupt can disturb this\n");
    printf("   __enable_irq();\n\n");

    printf("4. Typical main loop pattern:\n");
    printf("   while(1)\n   {\n");
    printf("       if(timer_flag)  { timer_flag=0;  handle_timer(); }\n");
    printf("       if(rx_ready)    { rx_ready=0;    process_uart(); }\n");
    printf("       if(button_flag) { button_flag=0; handle_button();}\n");
    printf("   }\n\n");

    /* Simulate the main loop */
    printf("5. Simulating ISR + main loop:\n");
    TIM2_IRQHandler();
    TIM2_IRQHandler();
    USART1_IRQHandler();
    EXTI0_IRQHandler();

    /* Main polling loop (simulated) */
    if(rx_ready)
    {
        printf("   UART data received: 0x%02X ('%c')\n", rx_byte, rx_byte);
        rx_ready = 0;
    }
    if(button_flag)
    {
        printf("   Button pressed! Handling event.\n");
        button_flag = 0;
    }
    printf("   Tick count: %lu\n", tick_count);

    printf("\n=== Interview Note ===\n");
    printf("Q: What should/shouldn't you do inside an ISR?\n");
    printf("A: DO  - set volatile flags, copy data, clear HW flags\n");
    printf("   DON'T- printf, malloc, long loops, delay functions\n");

    return 0;
}
