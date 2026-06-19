/*
 * Program  : Conditional Compilation
 * Author   : PAVAN SHETTY H S
 * Topic    : Preprocessor Directives
 *
 * Conditional compilation lets you include/exclude code
 * based on preprocessor conditions.
 * Very useful in embedded for:
 * - Enabling debug prints only during development
 * - Supporting multiple hardware boards
 * - Platform-specific code
 *
 * Expected Output: depends on which macros are defined
 */

#include <stdio.h>

/* Define to enable debug mode (comment out for release build) */
#define DEBUG_MODE  1
#define BOARD_STM32 1

/* Debug print macro - does nothing in release mode */
#ifdef DEBUG_MODE
    #define DEBUG_PRINT(msg) printf("[DEBUG] %s\n", msg)
    #define DEBUG_VAL(label, val) printf("[DEBUG] %s = %d\n", label, val)
#else
    #define DEBUG_PRINT(msg)         /* empty - compiles to nothing */
    #define DEBUG_VAL(label, val)    /* empty */
#endif

int main()
{
    printf("=== Conditional Compilation Demo ===\n\n");

    /* Board-specific code */
#ifdef BOARD_STM32
    printf("Compiling for: STM32 board\n");
    printf("Clock: 72 MHz\n");
#elif defined(BOARD_AVR)
    printf("Compiling for: AVR board\n");
    printf("Clock: 16 MHz\n");
#elif defined(BOARD_ESP32)
    printf("Compiling for: ESP32 board\n");
    printf("Clock: 240 MHz\n");
#else
    printf("Compiling for: Unknown board\n");
#endif

    /* Debug prints - only active if DEBUG_MODE is defined */
    int sensor_val = 512;
    DEBUG_PRINT("Sensor read started");
    DEBUG_VAL("sensor_val", sensor_val);

    printf("\nSensor value: %d\n", sensor_val);
    DEBUG_PRINT("Processing complete");

#ifdef DEBUG_MODE
    printf("\n[Build: DEBUG mode - extra checks enabled]\n");
#else
    printf("\n[Build: RELEASE mode - optimized]\n");
#endif

    /* __DATE__, __TIME__, __FILE__, __LINE__ - built-in macros */
    printf("\nBuilt on: %s at %s\n", __DATE__, __TIME__);
    printf("File: %s, Line: %d\n", __FILE__, __LINE__);

    return 0;
}
