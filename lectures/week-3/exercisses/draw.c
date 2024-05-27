#include <stdio.h>

// Draw algorithm
// Draws a pyramid of hashes
// O(n^2) time complexity

// Pseudocode:
// if n is 0:
//     return
// draw n - 1
// print n hashes

void draw(int n);

int main(void)
{
    int height;

    printf("Enter a number: ");
    scanf("%d", &height);

    draw(height);
}

void draw(int n)
{
    if (n == 0)
        return;

    draw(n - 1);

    for (int i = 0; i < n; i++)
        printf("#");
    printf("\n");
}