#include <stdio.h>

int main(void)
{
    char *s = "HI!"; // a string is just a pointer to the first character

    printf("String: %s\n", s);
    printf("String address: %p\n", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("Character address (%c): %p\n", s[i], &s[i]);
    }
}