#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    int coins = 0;
    int coin_values[] = {25, 10, 5, 1};

    do
    {
        change = get_int("Change: ");
    } while (change < 1);

    for (int i = 0; i < 4; i++)
    {
        if (change >= coin_values[i])
        {
            coins += change / coin_values[i];
            change = change % coin_values[i];
        }
    }

    printf("%d \n", coins);
}
