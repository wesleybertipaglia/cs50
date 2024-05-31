#include <stdio.h>

int main(void)
{
    int i, j;

    printf("i: ");
    scanf("%d", &i);

    printf("j: ");
    scanf("%d", &j);

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}