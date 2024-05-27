#include <stdlib.h>

int main(void)
{
    float totalCart = 15.50;
    float cash = 20.00;

    if (cash > totalCart)
    {
        printf("There is your change: %.2f\n", cash - totalCart);
        printf("Thank you for shopping with us!\n");
    }
    else
    {
        printf("Insufficient funds\n");
    }
}