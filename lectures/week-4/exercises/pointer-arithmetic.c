#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c", *s);         // same as s[0]
    printf("%c", *(s + 1));   // same as s[1]
    printf("%c\n", *(s + 2)); // same as s[2]
}