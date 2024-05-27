#include <stdlib.h>

int main(void)
{
    int manyTimesSayMeow;

    printf("How many times do you want me to say meow? ");
    scanf("%d", &manyTimesSayMeow);

    for (int i = 0; i < manyTimesSayMeow; i++)
    {
        printf("Meow\n");
    }
}