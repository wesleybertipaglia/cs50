#include <stdlib.h>

int main(void)
{
    char c;

    printf("Do you agree? [y/n]: ");
    scanf("%c", &c);

    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
    else
    {
        printf("Invalid input.\n");
    }
}