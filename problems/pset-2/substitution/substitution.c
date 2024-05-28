#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        key[i] = toupper(key[i]);
        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = encipher(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
}

string encipher(string plaintext, string key)
{
    string ciphertext = plaintext;
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }
    }
    return ciphertext;
}
