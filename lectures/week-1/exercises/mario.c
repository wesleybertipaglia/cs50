#include <stdio.h>

// defining functions
void horizontalBlocks();
void verticalBlocks();
void groupBlocks();
void promptGroupBlocks(int size);

int main(void)
{
    horizontalBlocks();
    verticalBlocks();
    groupBlocks();

    int size;
    do
    {
        size = get_int("Size: ");
    } while (size < 1);
    promptGroupBlocks(size);
}

void horizontalBlocks()
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}

void verticalBlocks()
{
    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
}

void groupBlocks()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void promptGroupBlocks(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}