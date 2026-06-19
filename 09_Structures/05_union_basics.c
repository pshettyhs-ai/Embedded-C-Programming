/*
 * Program  : Union in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * A union is like a struct but ALL members SHARE the same memory.
 * Size of union = size of its LARGEST member.
 * Only one member holds valid data at a time.
 *
 * Very useful in embedded: type punning, register bit fields,
 * saving RAM in memory-limited MCUs.
 *
 * Expected Output:
 * Size of struct: 7 bytes (or more with padding)
 * Size of union:  4 bytes (only largest member)
 */

#include <stdio.h>

/* Struct: each member gets its OWN memory */
struct MyStruct {
    int   a;   /* 4 bytes */
    short b;   /* 2 bytes */
    char  c;   /* 1 byte  */
};             /* total: at least 7 bytes */

/* Union: all members SHARE memory */
union MyUnion {
    int   a;   /* 4 bytes */
    short b;   /* 2 bytes */
    char  c;   /* 1 byte  */
};             /* total: 4 bytes (size of int) */

/* Embedded: Union for register access (bit fields) */
union StatusReg {
    unsigned char all_bits;
    struct {
        unsigned char ready   : 1;  /* bit 0 */
        unsigned char error   : 1;  /* bit 1 */
        unsigned char tx_full : 1;  /* bit 2 */
        unsigned char rx_empty: 1;  /* bit 3 */
        unsigned char reserved: 4;  /* bits 4-7 */
    } bits;
};

int main()
{
    printf("Size of struct: %lu bytes\n", sizeof(struct MyStruct));
    printf("Size of union : %lu bytes\n", sizeof(union MyUnion));

    union MyUnion u;
    u.a = 0x41424344;  /* 'DCBA' in ASCII */
    printf("\nAfter u.a = 0x41424344:\n");
    printf("u.a = 0x%X\n", u.a);
    printf("u.b = 0x%X\n", u.b);  /* only lower 2 bytes */
    printf("u.c = 0x%X ('%c')\n", u.c, u.c); /* only lower byte */

    /* Embedded: Status register access */
    printf("\n--- Status Register Demo ---\n");
    union StatusReg status;
    status.all_bits = 0x05;  /* 0000 0101 */
    printf("Full byte: 0x%02X\n", status.all_bits);
    printf("Ready bit : %d\n", status.bits.ready);
    printf("Error bit : %d\n", status.bits.error);
    printf("TX Full   : %d\n", status.bits.tx_full);
    printf("RX Empty  : %d\n", status.bits.rx_empty);

    /* Interview Note:
     * Q: Difference between struct and union?
     * A: struct = each member has its own memory (total = sum of all)
     *    union  = all members share the SAME memory (total = largest)
     *    Use union to save RAM or for type punning (register bitfields).
     */

    return 0;
}
