#include <stdio.h>

typedef char *string;

int main(void)
{
    string s = "HI!"; // a string is just a pointer to the first character

    printf("String: %s\n", s);
}