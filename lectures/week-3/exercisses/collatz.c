#include <stdio.h>

// Collatz conjecture algorithm
// The Collatz conjecture is a conjecture in mathematics that concerns a sequence defined as follows:

// Pseudocode:
// if n is 1:
//     return
// if n is even:
//     n = n / 2
// else:
//     n = 3n + 1
// collatz(n)

void collatz(int n);

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    collatz(n);
}

void collatz(int n)
{
    if (n == 1)
        return;
    else if (n % 2 == 0)
        n = n / 2;
    else
        n = 3 * n + 1;

    printf("%d\n", n);
    collatz(n);
}