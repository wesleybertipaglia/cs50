#include <stdio.h>

// Fibonacci sequence algorithm
// Generates the nth Fibonacci number
// O(2^n) time complexity

// Pseudocode:
// if n is 0:
//     return 0
// else if n is 1:
//     return 1
// else:
//     return fibonacci(n - 1) + fibonacci(n - 2)

int fibonacci(int n);

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Fibonacci of %d is %d\n", n, fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}