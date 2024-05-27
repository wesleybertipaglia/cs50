#include <stdio.h>

float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);

int main(void)
{
    float num1, num2;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
    printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
    printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
    printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
}

float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}