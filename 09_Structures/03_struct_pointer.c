/*
 * Program  : Pointer to Structure
 * Author   : PAVAN SHETTY H S
 * Topic    : Structures
 *
 * Pointer to struct allows efficient passing to functions
 * (no need to copy the whole struct).
 * Use -> operator to access members through pointer.
 *
 * Expected Output:
 * Name: PAVAN SHETTY H S, Age: 21, GPA: 8.50
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  name[50];
    int   age;
    float gpa;
} Student;

/* Pass struct by pointer - efficient, no copy */
void print_student(Student *s)
{
    /* Use -> operator with pointer */
    printf("Name: %s, Age: %d, GPA: %.2f\n", s->name, s->age, s->gpa);
}

void update_gpa(Student *s, float new_gpa)
{
    s->gpa = new_gpa;  /* modifies original struct! */
}

int main()
{
    Student s1;
    strcpy(s1.name, "PAVAN SHETTY H S");
    s1.age = 21;
    s1.gpa = 8.5f;

    print_student(&s1);

    /* -> vs . */
    Student *ptr = &s1;
    printf("Using dot  : %s\n", s1.name);    /* direct access */
    printf("Using arrow: %s\n", ptr->name);  /* pointer access */
    /* ptr->name  is same as  (*ptr).name */

    update_gpa(&s1, 9.0f);
    printf("After GPA update: ");
    print_student(&s1);

    return 0;
}
