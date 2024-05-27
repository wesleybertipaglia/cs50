#include <stdio.h>

int main(void)
{
    int x = 10, y = 20;

    if (x > y)
    {
        printf("%d is greater than %d\n", x, y);
    }
    else if (x < y)
    {
        printf("%d is greater than %d\n", y, x);
    }
    else
    {
        printf("%d is equal to %d\n", x, y);
    }
}