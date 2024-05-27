#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int player1Score = 0, player2Score = 0;

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    struct alphabet
    {
        char letter[26];
        int value[26];
    };

    struct alphabet alphabet = {
        .letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        .value = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}};

    for (int i = 0; i < strlen(player1); i++)
    {
        if (isalpha(player1[i]))
        {
            char upper_char = toupper(player1[i]);
            for (int j = 0; j < 26; j++)
            {
                if (alphabet.letter[j] == upper_char)
                {
                    player1Score += alphabet.value[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < strlen(player2); i++)
    {
        if (isalpha(player2[i]))
        {
            char upper_char = toupper(player2[i]);
            for (int j = 0; j < 26; j++)
            {
                if (alphabet.letter[j] == upper_char)
                {
                    player2Score += alphabet.value[j];
                    break;
                }
            }
        }
    }

    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
