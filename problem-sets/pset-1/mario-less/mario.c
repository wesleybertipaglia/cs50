#include <cs50.h>
#include <stdio.h>

void print_row(int height, int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1);

    for (int i = 0; i < n; i++)
    {
        print_row(n, i + 1);
    }
}

void print_row(int height, int bricks)
{
    for (int i = 0; i < height - bricks; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
