#include <stdio.h>

int main(void)
{
    char name[20];

    printf("%i %i %i %i", &name[0], &name[1], &name[2]);
}