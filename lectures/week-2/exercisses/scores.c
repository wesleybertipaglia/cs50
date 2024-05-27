#include <stdio.h>

int sum(int scores[], int size);
int average(int scores[], int size);

int main(void)
{
    int scores[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    printf("SUM = %d\n", sum(scores, 5));
    printf("AVERAGE = %d\n", average(scores, 5));
}

int sum(int scores[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }

    return sum;
}

int average(int scores[], int size)
{
    return sum(scores, size) / size;
}