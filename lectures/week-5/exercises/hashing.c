#include <stdio.h>
#include <ctype.h>

int hash(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return -1;
    }

    return toupper(*s) - 'A';
}

int main(void)
{
    char *s = "hello";
    printf("%d\n", hash(s));
}