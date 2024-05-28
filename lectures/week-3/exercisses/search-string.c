#include <stdio.h>
#include <string.h>

int main(void)
{
    char *texts[] = {"battleship", "bot", "cannon", "iron"};
    char target[50];

    printf("Text: ");
    scanf("%s", target);

    for (int i = 0; i < strlen(target); i++)
    {
        if (strcmp(target, texts[i]) == 0)
        {
            printf("Found at: %d\n", i);
            return 0;
        }
    }

    printf("Not found\n");
    return -1;
}