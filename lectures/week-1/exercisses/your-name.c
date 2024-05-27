#include <stdio.h>

int main(void)
{
    char name[20];

    printf("Hello, what is your name? ");
    scanf("%s", name);

    printf("Nice to meet you, %s!\n", name);
}