# Pointers Interview Q&A

**Prepared by:** PAVAN SHETTY H S  
**Topic:** Pointers in C — most asked in embedded interviews!

---

## Quick Reference — Pointer Declarations

```c
int  *p;           // pointer to int
int **pp;          // pointer to pointer to int
int  *p[5];        // array of 5 int pointers
int (*p)[5];       // pointer to array of 5 ints
int  *f();         // function returning int pointer
int (*f)();        // pointer to function returning int
const int *p;      // pointer to const int (value can't change)
int * const p;     // const pointer to int (address can't change)
volatile int *p;   // pointer to volatile int (for hardware registers!)
```

---

**Q1. What is the output of this program?**

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;
printf("%d\n", *(p + 2));   // ?
printf("%d\n", p[3]);       // ?
printf("%d\n", *(arr + 1)); // ?
```

**Answer:**
```
30   // *(p + 2) = arr[2] = 30
40   // p[3] = arr[3] = 40
20   // *(arr + 1) = arr[1] = 20
```
`arr[i]` and `*(arr + i)` are exactly the same!

---

**Q2. What is the output?**

```c
int x = 5;
int *p = &x;
*p = *p + 3;
printf("%d\n", x);  // ?
```

**Answer:** `8`  
`*p = *p + 3` → dereferences p to get 5, adds 3, stores 8 back at x's address.

---

**Q3. What is the size of a pointer?**

- On a **32-bit** system: 4 bytes (regardless of type)
- On a **64-bit** system: 8 bytes

```c
int    *pi;  char   *pc;  float  *pf;
sizeof(pi) == sizeof(pc) == sizeof(pf)  // all same size!
```

On most embedded MCUs (ARM Cortex-M, AVR): **4 bytes** (32-bit address space).

---

**Q4. What is a void pointer? What can and can't you do with it?**

```c
void *vp;
int a = 10;
vp = &a;        // OK: void* can hold any address

// *vp = 5;     // ERROR: cannot dereference void* without cast
int *ip = (int*)vp;
*ip = 5;        // OK after casting

// vp++;        // ERROR: cannot do pointer arithmetic on void*
```

**Use in embedded:** `memcpy(void *dst, const void *src, size_t n)` uses void* to work with any data type.

---

**Q5. What is the difference between `int *const p` and `const int *p`?**

```c
int a = 10, b = 20;

// const pointer — address fixed, value can change
int * const p1 = &a;
*p1 = 50;    // OK
// p1 = &b;  // ERROR: can't change address

// pointer to const — value fixed, address can change
const int *p2 = &a;
p2 = &b;     // OK
// *p2 = 50; // ERROR: can't change value through this pointer
```

---

**Q6. Predict the output:**

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d\n", **pp);   // ?
**pp = 99;
printf("%d\n", a);      // ?
```

**Answer:**
```
10
99
```
`**pp` → dereference twice: pp → p → a. Modifying `**pp` changes `a`.

---

**Q7. What is a wild pointer?**

A wild (uninitialized) pointer holds a garbage address and accessing it causes undefined behavior.

```c
int *p;      // wild pointer! contains garbage address
*p = 10;     // CRASH — writing to unknown memory location!

// Fix: always initialize
int *p = NULL;
int x;
int *p2 = &x;
```

> In embedded systems, wild pointers can corrupt registers or stack — very dangerous!

---

**Q8. What is the output?**

```c
char str[] = "Embedded";
char *p = str;
while(*p != '\0') {
    printf("%c", *p);
    p++;
}
```

**Answer:** `Embedded`  
The pointer traverses the string character by character until null terminator.

---

**Q9. How do you pass an array to a function and modify it?**

```c
// Array decays to pointer when passed to function
void double_array(int *arr, int n) {
    int i;
    for(i = 0; i < n; i++)
        arr[i] *= 2;   // modifies original array!
}

int main() {
    int data[] = {1, 2, 3};
    double_array(data, 3);
    // data is now {2, 4, 6}
}
```

No need to pass `&data` — the array name already decays to a pointer.

---

**Q10. Write a swap function using pointers.**

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    // x = 10, y = 5
}
```

Alternatively, using XOR (no temp variable):
```c
void swap_xor(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
```

---

**Q11. What is a function pointer? Write an example.**

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    // declare: return_type (*name)(params)
    int (*op)(int, int);

    op = add;
    printf("%d\n", op(5, 3));  // 8

    op = sub;
    printf("%d\n", op(5, 3));  // 2

    // Array of function pointers (state machine / dispatch table)
    int (*ops[2])(int, int) = {add, sub};
    printf("%d\n", ops[0](10, 4));  // 14
    printf("%d\n", ops[1](10, 4));  // 6
}
```

**Embedded use:** ISR vector tables, callback registration, command dispatch.

---

**Q12. What does this print?**

```c
int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int *p = &arr[0][0];
printf("%d\n", *(p + 5));   // ?
printf("%d\n", *(p + 10));  // ?
```

**Answer:**
```
6    // p+5 = arr[1][1] (5th element from start = index 5)
11   // p+10 = arr[2][2]
```
2D array is contiguous in memory: 1,2,3,4,5,6,7,8,9,10,11,12

---

*Note from Pavan: Pointers tripped me up initially but once I visualized memory addresses on paper, it became clearer. Draw boxes for variables and arrows for pointers!*
