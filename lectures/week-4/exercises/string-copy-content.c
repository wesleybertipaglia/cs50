#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s;

    printf("s: ");
    scanf("%s", s);

    // to copy the content of s to t, we need to allocate memory for t + 1 byte for the \0 character
    char *t = malloc(strlen(s) + 1); // return a pointer to the first byte of the allocated memory

    if (s == NULL || t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t); // free the memory allocated for t to avoid memory leak
}