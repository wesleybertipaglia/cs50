#include <stdio.h>

// Factorial algorithm
// Calculates the factorial of a positive integer
// O(n) time complexity

// Pseudocode:
// if n is 0 or 1:
//     return 1
// else:
//     return n * factorial(n - 1)

int factorial(int n);

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}