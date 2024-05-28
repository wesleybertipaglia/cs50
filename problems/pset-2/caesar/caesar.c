#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

string encipher(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("Plaintext: ");
    string ciphertext = encipher(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
}

string encipher(string plaintext, int key)
{
    int textlen = strlen(plaintext);
    char *ciphertext = malloc(textlen + 1);

    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + key) % 26 + base;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}
