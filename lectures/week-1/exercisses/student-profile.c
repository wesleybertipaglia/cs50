#include <stdlib.h>

int main(void)
{
    char name[50];
    int age;
    float gpa;
    char grade;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA (of 10 or 5): ");
    scanf("%f", &gpa);

    printf("Enter your grade (A, B, C): ");
    scanf(" %c", &grade);

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
}