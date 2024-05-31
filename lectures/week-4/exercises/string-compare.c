#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10], t[10];

    printf("s: ");
    scanf("%s", s);

    printf("t: ");
    scanf("%s", t);

    printf("Compare the address of the two strings: ");
    if (s == t) // compare the address of the two strings and it will always be different
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    printf("Compare the content of the two strings: ");
    if (strcmp(s, t) == 0) // compare the content of the two strings
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}