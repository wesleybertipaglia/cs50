#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool checkLuhn(long number);
bool isValidAmex(long number);
bool isValidMastercard(long number);
bool isValidVisa(long number);
int getLength(long number);
int getFirstDigits(long number, int digits);

int main(void)
{
    long card_number = get_long("Number: ");

    if (checkLuhn(card_number))
    {
        if (isValidAmex(card_number))
        {
            printf("AMEX\n");
        }
        else if (isValidMastercard(card_number))
        {
            printf("MASTERCARD\n");
        }
        else if (isValidVisa(card_number))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checkLuhn(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10) == 0;
}

bool isValidAmex(long number)
{
    int length = getLength(number);
    int first_two_digits = getFirstDigits(number, 2);

    return (length == 15 && (first_two_digits == 34 || first_two_digits == 37));
}

bool isValidMastercard(long number)
{
    int length = getLength(number);
    int first_two_digits = getFirstDigits(number, 2);

    return (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55));
}

bool isValidVisa(long number)
{
    int length = getLength(number);
    int first_digit = getFirstDigits(number, 1);

    return ((length == 13 || length == 16) && first_digit == 4);
}

int getLength(long number)
{
    int length = 0;

    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int getFirstDigits(long number, int digits)
{
    int length = getLength(number);

    for (int i = 0; i < (length - digits); i++)
    {
        number /= 10;
    }
    return number;
}
