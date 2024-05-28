#include <stdio.h>

// Recursion algorithm
// A function that calls itself
// O(n) time complexity

// Pseudocode of a factorial function:
// if n is 0:
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
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
