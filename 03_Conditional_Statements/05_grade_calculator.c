/*
 * Program  : Grade Calculator using Conditional Statements
 * Author   : PAVAN SHETTY H S
 * Topic    : Conditional Statements
 *
 * Description:
 * A simple grade calculator. Combines if-else and switch together.
 *
 * Expected Output:
 * Enter your marks (out of 100): 82
 * Grade: B
 * Result: PASS
 * Percentage: 82.00%
 */

#include <stdio.h>

int main()
{
    int marks;
    char grade;

    printf("Enter your marks (out of 100): ");
    scanf("%d", &marks);

    /* Validate input */
    if (marks < 0 || marks > 100)
    {
        printf("Invalid marks! Please enter between 0 and 100.\n");
        return 1;  /* exit with error code */
    }

    /* Assign grade using if-else */
    if (marks >= 90)
        grade = 'A';
    else if (marks >= 80)
        grade = 'B';
    else if (marks >= 70)
        grade = 'C';
    else if (marks >= 60)
        grade = 'D';
    else
        grade = 'F';

    /* Display result using switch */
    printf("Grade: %c\n", grade);

    switch(grade)
    {
        case 'A': printf("Excellent Performance!\n"); break;
        case 'B': printf("Good Performance!\n");      break;
        case 'C': printf("Average Performance.\n");   break;
        case 'D': printf("Below Average. Improve.\n");break;
        case 'F': printf("Failed. Better luck next time.\n"); break;
    }

    if (marks >= 40)
        printf("Result: PASS\n");
    else
        printf("Result: FAIL\n");

    printf("Percentage: %.2f%%\n", (float)marks);

    return 0;
}
