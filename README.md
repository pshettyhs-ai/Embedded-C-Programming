# Embedded C Programming 🔧

<div align="center">

![Embedded C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Microcontrollers](https://img.shields.io/badge/Domain-Embedded%20Systems-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Learning%20in%20Progress-orange?style=for-the-badge)
![Author](https://img.shields.io/badge/Author-PAVAN%20SHETTY%20H%20S-red?style=for-the-badge)

</div>

---

## 👋 About Me

**Name:** PAVAN SHETTY H S  
**Branch:** Electronics and Communication Engineering (ECE)  
**Interests:** Embedded Systems | IoT | Microcontroller Programming | Embedded C | RTOS  

Hi! I'm Pavan, an ECE student who is really interested in how hardware and software work together. I started this repository to document my learning journey in Embedded C programming. I'm preparing for Embedded Software Engineer roles and also trying to build strong fundamentals in microcontroller programming.

This is my personal learning space — not a professional course. I'm still learning, so the code gets better as you go deeper into the folders! 😄

---

## 🎯 Repository Objective

- Learn Embedded C from the very basics to advanced concepts
- Practice programs related to microcontroller peripherals (GPIO, UART, SPI, I2C, Timers, PWM)
- Understand how C works at a low level — memory, pointers, bitwise operations
- Prepare well for Embedded Systems and Firmware Engineer interviews
- Build a reference that I (and other ECE students) can use during interview prep

---

## 📚 Topics Covered

### C Programming Fundamentals
| # | Topic | Folder |
|---|-------|--------|
| 1 | Basics of C – Hello World, Variables, Data Types | `01_Basics/` |
| 2 | Operators – Arithmetic, Relational, Logical | `02_Operators/` |
| 3 | Conditional Statements – if, else, switch | `03_Conditional_Statements/` |
| 4 | Loops – for, while, do-while | `04_Loops/` |
| 5 | Functions – declaration, definition, recursion | `05_Functions/` |
| 6 | Arrays – 1D, 2D, operations | `06_Arrays/` |
| 7 | Strings – string functions, manipulation | `07_Strings/` |
| 8 | Pointers – pointer basics, pointer arithmetic | `08_Pointers/` |
| 9 | Structures – struct, union, typedef | `09_Structures/` |
| 10 | Dynamic Memory Allocation – malloc, calloc, free | `10_Dynamic_Memory/` |
| 11 | Bitwise Operators – AND, OR, XOR, shifts | `11_Bitwise_Operators/` |
| 12 | Preprocessor Directives – #define, #include, macros | `12_Preprocessor/` |

### Embedded C Concepts
| # | Topic | Folder |
|---|-------|--------|
| 13 | Embedded C Concepts – volatile, register, storage classes, interrupts | `13_Embedded_C_Concepts/` |
| 14 | GPIO Programming – LED blink, button input | `14_GPIO_Examples/` |
| 15 | UART Communication – serial transmit/receive | `15_UART_Examples/` |
| 16 | SPI Communication – master/slave protocol | `16_SPI_Examples/` |
| 17 | I2C Communication – two-wire interface | `17_I2C_Examples/` |

---

## 🗂️ Folder Structure

```
Embedded-C-Programming/
│
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── .gitignore
│
├── 01_Basics/
│   ├── 01_hello_world.c
│   ├── 02_variables_datatypes.c
│   ├── 03_constants.c
│   ├── 04_type_casting.c
│   ├── 05_input_output.c
│   ├── 06_storage_classes.c
│   └── README.md
│
├── 02_Operators/
│   ├── 01_arithmetic_operators.c
│   ├── 02_relational_operators.c
│   ├── 03_logical_operators.c
│   ├── 04_assignment_operators.c
│   ├── 05_increment_decrement.c
│   ├── 06_ternary_operator.c
│   └── README.md
│
├── 03_Conditional_Statements/
│   ├── 01_if_else.c
│   ├── 02_if_else_ladder.c
│   ├── 03_nested_if.c
│   ├── 04_switch_case.c
│   ├── 05_grade_calculator.c
│   └── README.md
│
├── 04_Loops/
│   ├── 01_for_loop.c
│   ├── 02_while_loop.c
│   ├── 03_do_while_loop.c
│   ├── 04_nested_loops.c
│   ├── 05_break_continue.c
│   ├── 06_pattern_printing.c
│   └── README.md
│
├── 05_Functions/
│   ├── 01_function_basics.c
│   ├── 02_call_by_value.c
│   ├── 03_call_by_reference.c
│   ├── 04_recursion.c
│   ├── 05_inline_functions.c
│   └── README.md
│
├── 06_Arrays/
│   ├── 01_1D_array.c
│   ├── 02_2D_array.c
│   ├── 03_array_operations.c
│   ├── 04_array_sorting.c
│   ├── 05_array_search.c
│   ├── 06_array_and_functions.c
│   └── README.md
│
├── 07_Strings/
│   ├── 01_string_basics.c
│   ├── 02_string_functions.c
│   ├── 03_string_reverse.c
│   ├── 04_string_palindrome.c
│   ├── 05_string_operations.c
│   └── README.md
│
├── 08_Pointers/
│   ├── 01_pointer_basics.c
│   ├── 02_pointer_arithmetic.c
│   ├── 03_pointer_and_arrays.c
│   ├── 04_pointer_to_pointer.c
│   ├── 05_function_pointers.c
│   ├── 06_void_pointer.c
│   └── README.md
│
├── 09_Structures/
│   ├── 01_struct_basics.c
│   ├── 02_struct_array.c
│   ├── 03_struct_pointer.c
│   ├── 04_nested_struct.c
│   ├── 05_union_basics.c
│   ├── 06_typedef.c
│   └── README.md
│
├── 10_Dynamic_Memory/
│   ├── 01_malloc_example.c
│   ├── 02_calloc_example.c
│   ├── 03_realloc_example.c
│   ├── 04_free_memory.c
│   ├── 05_dynamic_array.c
│   └── README.md
│
├── 11_Bitwise_Operators/
│   ├── 01_bitwise_basics.c
│   ├── 02_set_clear_toggle_bit.c
│   ├── 03_check_bit.c
│   ├── 04_bit_shifting.c
│   ├── 05_swap_using_xor.c
│   ├── 06_count_set_bits.c
│   ├── 07_gpio_bit_manipulation.c
│   └── README.md
│
├── 12_Preprocessor/
│   ├── 01_define_macro.c
│   ├── 02_macro_functions.c
│   ├── 03_conditional_compilation.c
│   ├── 04_header_guards.c
│   ├── 05_include_files.c
│   └── README.md
│
├── 13_Embedded_C_Concepts/
│   ├── 01_volatile_keyword.c
│   ├── 02_const_keyword.c
│   ├── 03_register_keyword.c
│   ├── 04_interrupt_basics.c
│   ├── 05_timer_concept.c
│   ├── 06_pwm_concept.c
│   ├── 07_memory_mapped_io.c
│   └── README.md
│
├── 14_GPIO_Examples/
│   ├── 01_led_blink.c
│   ├── 02_led_button_control.c
│   ├── 03_multiple_leds.c
│   ├── 04_led_patterns.c
│   ├── 05_gpio_register_access.c
│   └── README.md
│
├── 15_UART_Examples/
│   ├── 01_uart_init.c
│   ├── 02_uart_transmit.c
│   ├── 03_uart_receive.c
│   ├── 04_uart_string_send.c
│   ├── 05_uart_echo.c
│   └── README.md
│
├── 16_SPI_Examples/
│   ├── 01_spi_init.c
│   ├── 02_spi_master_transmit.c
│   ├── 03_spi_slave_receive.c
│   ├── 04_spi_full_duplex.c
│   └── README.md
│
├── 17_I2C_Examples/
│   ├── 01_i2c_init.c
│   ├── 02_i2c_master_write.c
│   ├── 03_i2c_master_read.c
│   ├── 04_i2c_sensor_read.c
│   └── README.md
│
└── Interview_Preparation/
    ├── Embedded_C_Interview_QA.md
    ├── Pointers_Interview_QA.md
    ├── Bitwise_Interview_QA.md
    └── README.md
```

---

## 🚀 My Learning Journey

I started this repository when I realized that just studying theory wasn't enough for cracking Embedded Systems interviews. So I decided to write actual programs for every concept I studied.

I began with basic C programs (which might look very simple!) and gradually moved to microcontroller-level concepts like GPIO, UART, SPI, and I2C. The code quality also improves as you go through later folders — that's just honest learning! 😅

I mostly referred to:
- *Let Us C* by Yashavant Kanetkar
- *The C Programming Language* by Kernighan & Ritchie
- Various microcontroller datasheets (AVR ATmega328, STM32)
- YouTube lectures and online embedded C tutorials

---

## 🔮 Future Goals

Things I want to explore next:

- [ ] **8051 Microcontroller Programming** – Assembly + Embedded C
- [ ] **Arduino Projects** – Sensors, displays, motor control
- [ ] **ESP32 Projects** – WiFi, Bluetooth, IoT applications
- [ ] **RTOS Basics** – FreeRTOS tasks, queues, semaphores
- [ ] **Device Driver Development** – Linux kernel modules
- [ ] **ARM Cortex-M Programming** – STM32 bare-metal
- [ ] **CAN Bus Communication** – Automotive protocols

---

## 🛠️ How to Compile and Run

All programs are written in standard C. You can compile them using GCC:

```bash
# Compile a program
gcc filename.c -o output

# Run it
./output
```

For embedded examples (GPIO, UART, SPI, I2C), the code is written for AVR/STM32 style registers. You'll need the respective toolchain:

```bash
# For AVR
avr-gcc -mmcu=atmega328p filename.c -o output.elf

# For ARM (STM32)
arm-none-eabi-gcc filename.c -o output.elf
```

---

## 🤝 Contributing

Found a bug or want to improve something? Feel free to open an issue or pull request!  
Check [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

---

## 📄 License

This project is licensed under the MIT License – see [LICENSE](LICENSE) for details.

---

## 📬 Connect With Me

If you're also an ECE student learning Embedded Systems, feel free to connect!

- **GitHub:** [PAVAN SHETTY H S](https://github.com/pshettyhs-ai)
- **LinkedIn:** [Pavan Shetty H S](https://www.linkedin.com/in/pavan-shetty-h-s1807/)
- **Email:** [pshettyhs@gmail.com](mailto:pshettyhs@gmail.com)

---

<div align="center">
  <i>"The best way to learn embedded systems is to actually write the code, burn it to a chip, and see the LED blink!" 💡</i>
  <br><br>
  <b>– PAVAN SHETTY H S</b>
</div>
