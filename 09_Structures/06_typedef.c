/*
 * Program  : typedef in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * typedef creates a new alias (name) for an existing type.
 * Used heavily in embedded C and microcontroller header files!
 * e.g., uint8_t, uint16_t, GPIO_TypeDef are all typedefs.
 *
 * Expected Output:
 * uint8_t  size: 1 byte
 * uint16_t size: 2 bytes
 * uint32_t size: 4 bytes
 */

#include <stdio.h>

/* typedef for basic types (similar to stdint.h) */
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef signed char    int8_t;
typedef signed short   int16_t;
typedef signed int     int32_t;

/* typedef for struct - no need to write 'struct' every time */
typedef struct {
    char  name[30];
    int   pin_number;
    uint8_t direction;  /* 0=input, 1=output */
    uint8_t state;      /* 0=low,   1=high */
} GPIO_Pin_t;

/* typedef for function pointer */
typedef void (*ISR_Handler_t)(void);

void timer_isr(void)  { printf("Timer ISR triggered!\n"); }
void uart_isr(void)   { printf("UART ISR triggered!\n"); }

int main()
{
    printf("--- Fixed-width types (like stdint.h) ---\n");
    printf("uint8_t  size: %lu byte\n",  sizeof(uint8_t));
    printf("uint16_t size: %lu bytes\n", sizeof(uint16_t));
    printf("uint32_t size: %lu bytes\n", sizeof(uint32_t));

    uint8_t  reg8  = 0xFF;
    uint16_t reg16 = 0x1234;
    uint32_t reg32 = 0xDEADBEEF;

    printf("\nreg8  = 0x%02X\n", reg8);
    printf("reg16 = 0x%04X\n",   reg16);
    printf("reg32 = 0x%08X\n",   reg32);

    /* GPIO struct using typedef */
    GPIO_Pin_t led = {"LED_Pin", 13, 1, 0};
    printf("\nGPIO Pin: %s, Pin#%d, Dir=%s, State=%s\n",
           led.name, led.pin_number,
           led.direction ? "OUTPUT" : "INPUT",
           led.state     ? "HIGH"   : "LOW");

    /* Function pointer typedef */
    printf("\n--- ISR Table using function pointer typedef ---\n");
    ISR_Handler_t isr_table[2] = {timer_isr, uart_isr};
    int i;
    for(i = 0; i < 2; i++)
        isr_table[i]();  /* trigger each ISR */

    return 0;
}
