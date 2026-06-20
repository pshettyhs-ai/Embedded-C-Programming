/*
 * Program  : UART Echo (Loopback) Application
 * Author   : PAVAN SHETTY H S
 * Topic    : UART Communication
 *
 * Echo test: everything received is sent back.
 * This is the simplest way to test UART is working.
 * Also shows a simple command interpreter pattern.
 *
 * Expected Output:
 * Echo and command processing demo
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/* ===== Simulated UART buffers ===== */
#define BUF_SIZE 128
static char rx_line[BUF_SIZE];
static int  rx_len = 0;

void UART_SendString(const char *s)
{
    printf("[TX] %s", s);
}

void process_command(const char *cmd)
{
    printf("\n--- Processing command: \"%s\" ---\n", cmd);

    if(strcmp(cmd, "HELLO") == 0)
    {
        UART_SendString("Hello from PAVAN SHETTY H S!\r\n");
    }
    else if(strcmp(cmd, "VERSION") == 0)
    {
        UART_SendString("FW Version: v1.0.0\r\n");
    }
    else if(strncmp(cmd, "LED=", 4) == 0)
    {
        const char *val = cmd + 4;
        if(strcmp(val, "ON") == 0)
            UART_SendString("LED turned ON\r\n");
        else if(strcmp(val, "OFF") == 0)
            UART_SendString("LED turned OFF\r\n");
        else
            UART_SendString("ERROR: Use LED=ON or LED=OFF\r\n");
    }
    else if(strcmp(cmd, "STATUS") == 0)
    {
        UART_SendString("STATUS: TEMP=27C, VOLT=3.3V, LED=ON\r\n");
    }
    else if(strcmp(cmd, "RESET") == 0)
    {
        UART_SendString("Resetting system...\r\n");
    }
    else
    {
        UART_SendString("ERROR: Unknown command\r\n");
        UART_SendString("Commands: HELLO, VERSION, LED=ON/OFF, STATUS, RESET\r\n");
    }
}

/* Simulate receiving a full command line */
void simulate_receive(const char *input)
{
    printf("\n[RX] Received: \"%s\"\n", input);

    /* Copy to line buffer, convert to uppercase */
    rx_len = 0;
    int i;
    for(i = 0; input[i] && input[i] != '\r' && input[i] != '\n'; i++)
    {
        rx_line[rx_len++] = toupper((unsigned char)input[i]);
    }
    rx_line[rx_len] = '\0';

    /* Echo back */
    char echo_msg[BUF_SIZE + 10];
    sprintf(echo_msg, "ECHO: %s\r\n", rx_line);
    UART_SendString(echo_msg);

    /* Process the command */
    process_command(rx_line);
}

int main()
{
    printf("=== UART Echo + Command Interpreter ===\n");
    printf("Simulating a terminal-based command interface\n");
    printf("----------------------------------------\n");

    /* Simulate receiving various commands */
    simulate_receive("hello\r\n");
    simulate_receive("version\r\n");
    simulate_receive("led=on\r\n");
    simulate_receive("status\r\n");
    simulate_receive("led=off\r\n");
    simulate_receive("blink\r\n");   /* unknown command */
    simulate_receive("reset\r\n");

    printf("\n--- Pattern Notes ---\n");
    printf("This command pattern is used in:\n");
    printf("  - AT command sets (GSM, WiFi, BT modules)\n");
    printf("  - Debug consoles over UART\n");
    printf("  - Industrial device configuration\n");

    return 0;
}
