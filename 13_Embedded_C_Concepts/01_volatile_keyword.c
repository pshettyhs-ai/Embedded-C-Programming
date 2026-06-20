/*
 * Program  : volatile Keyword in Embedded C
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * volatile tells the compiler:
 * "Do NOT optimize this variable - always read it fresh from memory!"
 *
 * WHY? Because in embedded systems, variables can change:
 * - By hardware (registers, DMA)
 * - By interrupts (ISR modifies shared variable)
 * - By another thread (RTOS)
 *
 * Without volatile: compiler may cache the value in a register
 * and never re-read it — causing bugs that are very hard to find!
 *
 * This is a TOP interview question for embedded roles!
 *
 * Expected Output:
 * Demo of volatile vs non-volatile behavior
 */

#include <stdio.h>
#include <stdint.h>

/* Without volatile - compiler might optimize this away! */
int normal_flag = 0;

/* With volatile - compiler will ALWAYS read from memory */
volatile int isr_flag = 0;

/* Simulated hardware register (always use volatile for registers!) */
volatile uint32_t *UART_STATUS = (volatile uint32_t*)0x40011000;
/* In real code: while(!(*UART_STATUS & 0x80)); // wait for TX ready */

/* volatile in ISR-shared variable */
volatile uint8_t  rx_buffer[64];
volatile uint8_t  rx_count = 0;

/* Simulated ISR (Interrupt Service Routine) */
void UART_RX_IRQHandler(void)
{
    /* In real code: this is called by hardware interrupt */
    rx_buffer[rx_count] = 'A';  /* simulating received byte */
    rx_count++;                  /* volatile - main() will see this change */
    isr_flag = 1;                /* signal to main loop */
}

int main()
{
    printf("=== volatile Keyword Demo ===\n\n");

    /* --- Why volatile matters --- */
    printf("1. Without volatile (risky pattern):\n");
    printf("   while(normal_flag == 0);  // compiler might optimize to: while(true)!\n");
    printf("   (If normal_flag is not volatile, compiler may never re-check it)\n");

    printf("\n2. With volatile (correct pattern):\n");
    printf("   while(isr_flag == 0);  // compiler always reads from memory\n");

    /* Simulate ISR being triggered */
    UART_RX_IRQHandler();  /* pretend interrupt fired */

    if(isr_flag)
    {
        printf("\nISR flag detected! Received %d bytes.\n", rx_count);
        printf("Data: %c\n", rx_buffer[0]);
        isr_flag = 0;  /* clear the flag */
    }

    /* --- volatile const --- */
    printf("\n3. volatile const pointer (read-only hardware register):\n");
    printf("   volatile const uint32_t *GPIO_IDR = ...\n");
    printf("   The register value changes by hardware (volatile),\n");
    printf("   but we only READ it, never write (const).\n");

    /* --- Summary --- */
    printf("\n=== Summary ===\n");
    printf("Use volatile for:\n");
    printf("  - Hardware registers (GPIO, UART, SPI)\n");
    printf("  - Variables shared between ISR and main code\n");
    printf("  - Variables changed by DMA\n");
    printf("  - Variables shared between RTOS tasks\n");
    printf("\nWithout volatile = compiler bug that only appears in optimized builds!\n");

    /* Interview Answer:
     * Q: What is volatile in C? When do you use it?
     * A: volatile prevents the compiler from optimizing reads/writes
     *    to a variable. The compiler will always generate a memory
     *    access instead of using a cached register value.
     *    Use for: hardware registers, ISR-shared vars, DMA buffers.
     */

    return 0;
}
