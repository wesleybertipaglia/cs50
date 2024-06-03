#include <stdio.h>

typedef struct
{
    int key;
    char *value;
} Dictionary;

int main(void)
{
    Dictionary fruits[] = {
        {0, "Apple"},
        {1, "Banana"},
        {2, "Cherry"}};

    for (int i = 0; i < 3; i++)
    {
        printf("Key: %d, Value: %s\n", i, fruits[i].value);
    }
}