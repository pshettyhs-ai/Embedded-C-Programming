/*
 * Program  : #include and File Organization
 * Author   : PAVAN SHETTY H S
 * Topic    : Preprocessor Directives
 *
 * #include copies the content of another file here.
 * <file.h> = system header (looks in system directories)
 * "file.h" = user header  (looks in current directory first)
 *
 * Common headers in embedded C:
 * #include <stdint.h>   - uint8_t, uint16_t, uint32_t
 * #include <stdbool.h>  - bool, true, false
 * #include <string.h>   - memcpy, memset, strlen
 * #include <stdlib.h>   - malloc, free, atoi
 * #include <stdio.h>    - printf, scanf (usually not in bare-metal!)
 */

#include <stdio.h>
#include <stdint.h>   /* fixed-width integer types */
#include <stdbool.h>  /* bool type */
#include <string.h>   /* memset, memcpy */
#include <stdlib.h>   /* atoi, abs */

int main()
{
    /* stdint.h types - very important for embedded! */
    uint8_t  a = 255;        /* 8-bit  unsigned: 0 to 255 */
    uint16_t b = 65535;      /* 16-bit unsigned */
    uint32_t c = 4294967295U;/* 32-bit unsigned */
    int8_t   d = -128;       /* 8-bit  signed */

    printf("uint8_t  max: %u\n",  a);
    printf("uint16_t max: %u\n",  b);
    printf("uint32_t max: %u\n",  c);
    printf("int8_t   min: %d\n",  d);

    /* stdbool.h */
    bool led_on    = true;
    bool button    = false;
    printf("\nLED: %s, Button: %s\n",
           led_on ? "ON" : "OFF", button ? "Pressed" : "Released");

    /* string.h: memset and memcpy (used heavily in embedded!) */
    uint8_t buf[8];
    memset(buf, 0x00, sizeof(buf));  /* zero-fill buffer */
    printf("\nBuffer after memset(0x00): ");
    int i;
    for(i = 0; i < 8; i++) printf("0x%02X ", buf[i]);
    printf("\n");

    uint8_t src[] = {0xDE, 0xAD, 0xBE, 0xEF};
    memcpy(buf, src, sizeof(src));   /* copy bytes */
    printf("Buffer after memcpy: ");
    for(i = 0; i < 8; i++) printf("0x%02X ", buf[i]);
    printf("\n");

    /* stdlib.h: atoi - convert string to int (for UART command parsing) */
    char num_str[] = "1234";
    int  num_val   = atoi(num_str);
    printf("\natoi(\"%s\") = %d\n", num_str, num_val);

    return 0;
}
