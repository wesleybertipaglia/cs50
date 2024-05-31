#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char *s;

    printf("s: ");
    scanf("%s", s);

    char *t = s;
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
}