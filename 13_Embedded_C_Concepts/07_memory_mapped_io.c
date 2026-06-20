/*
 * Program  : Memory-Mapped I/O in Embedded C
 * Author   : PAVAN SHETTY H S
 * Topic    : Embedded C Concepts
 *
 * Memory-mapped I/O means hardware registers are placed
 * at specific memory addresses. To access hardware, you just
 * read/write to those addresses using pointers!
 *
 * This is how ALL MCU peripheral access works:
 *   - GPIO registers
 *   - UART registers
 *   - Timer registers
 *   - ADC registers
 *
 * Expected Output:
 * Memory-mapped I/O concept demonstration
 */

#include <stdio.h>
#include <stdint.h>

/* ===== Simulated STM32 Register Addresses ===== */
/* In real MCU, these are actual hardware addresses */
#define GPIOA_BASE      0x40020000UL
#define GPIOB_BASE      0x40020400UL

/* GPIO Register offsets */
#define GPIOx_MODER     0x00  /* Mode register */
#define GPIOx_ODR       0x14  /* Output data register */
#define GPIOx_IDR       0x10  /* Input data register */
#define GPIOx_BSRR      0x18  /* Bit set/reset register */

/* Macros to access registers */
#define REG32(addr)     (*((volatile uint32_t*)(addr)))
#define GPIOA_MODER     REG32(GPIOA_BASE + GPIOx_MODER)
#define GPIOA_ODR       REG32(GPIOA_BASE + GPIOx_ODR)
#define GPIOA_IDR       REG32(GPIOA_BASE + GPIOx_IDR)

/* ===== Simulated register memory ===== */
static uint32_t sim_GPIOA_MODER = 0;
static uint32_t sim_GPIOA_ODR   = 0;
static uint32_t sim_GPIOA_IDR   = 0b00000100;  /* simulate pin2 HIGH */

int main()
{
    printf("=== Memory-Mapped I/O Concepts ===\n\n");

    printf("In embedded C, hardware registers are at fixed addresses.\n");
    printf("We access them using pointers:\n\n");

    printf("  volatile uint32_t *GPIOA_ODR = (volatile uint32_t*)0x40020014;\n");
    printf("  *GPIOA_ODR |= (1 << 5);  // Set PA5 HIGH\n\n");

    /* Simulate register access */
    printf("--- Simulated GPIO Register Operations ---\n\n");

    printf("GPIOA Base Address : 0x%08X\n", (unsigned)GPIOA_BASE);
    printf("GPIOA_MODER offset : 0x%02X  -> addr 0x%08X\n",
           GPIOx_MODER, (unsigned)(GPIOA_BASE + GPIOx_MODER));
    printf("GPIOA_ODR   offset : 0x%02X  -> addr 0x%08X\n",
           GPIOx_ODR,   (unsigned)(GPIOA_BASE + GPIOx_ODR));
    printf("GPIOA_IDR   offset : 0x%02X  -> addr 0x%08X\n",
           GPIOx_IDR,   (unsigned)(GPIOA_BASE + GPIOx_IDR));

    printf("\nSimulated operations:\n");

    /* Configure PA5 as output (bits 11:10 = 01) */
    sim_GPIOA_MODER &= ~(0x3U << 10);   /* clear bits */
    sim_GPIOA_MODER |=  (0x1U << 10);   /* set as output */
    printf("MODER after PA5=OUTPUT: 0x%08X\n", sim_GPIOA_MODER);

    /* Set PA5 HIGH */
    sim_GPIOA_ODR |= (1U << 5);
    printf("ODR after PA5=HIGH: 0x%08X\n", sim_GPIOA_ODR);

    /* Read PA2 */
    int pa2_state = (sim_GPIOA_IDR >> 2) & 1;
    printf("IDR PA2 state: %d (%s)\n", pa2_state, pa2_state ? "HIGH" : "LOW");

    printf("\nKey Point:\n");
    printf("ALWAYS use 'volatile' when accessing hardware registers!\n");
    printf("Otherwise compiler may optimize away the reads/writes.\n");

    return 0;
}
