#include <stdio.h>
#include <string.h>

int main(void)
{
    char phrase[20];

    printf("Enter a phrase: ");
    scanf("%s", phrase);

    for (int i = 0; i < strlen(phrase) - 1; i++)
    {
        if (phrase[i] > phrase[i + 1])
        {
            printf("The phrase is not alphabetical\n");
            return 0;
        }
        else
        {
            continue;
        }
    }

    printf("The phrase is alphabetical\n");
    return 0;
}