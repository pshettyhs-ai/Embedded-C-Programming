/*
 * Program  : do-while Loop in C
 * Author   : PAVAN SHETTY H S
 * Topic    : Loops
 *
 * do-while: body executes AT LEAST ONCE, then condition is checked.
 * Key difference from while: executes minimum 1 time.
 *
 * Expected Output:
 * Menu appears at least once even before checking condition.
 */

#include <stdio.h>

int main()
{
    int choice;

    /* Menu using do-while - executes at least once */
    do {
        printf("\n===== MENU =====\n");
        printf("1. Option One\n");
        printf("2. Option Two\n");
        printf("3. Option Three\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("You selected Option One\n");   break;
            case 2: printf("You selected Option Two\n");   break;
            case 3: printf("You selected Option Three\n"); break;
            case 0: printf("Exiting...\n");                break;
            default: printf("Invalid choice!\n");          break;
        }
    } while(choice != 0);  /* keep looping until user enters 0 */

    /* do-while comparison:
     * while  : may never execute (if condition is false from start)
     * do-while: ALWAYS executes at least once
     */

    return 0;
}
