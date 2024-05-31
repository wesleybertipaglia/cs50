#include <stdio.h>

void encrypt(char *message, int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] + key;
    }
}

void decrypt(char *message, int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] - key;
    }
}

int main()
{
    char message[] = "Hello, world!";
    int key = 3;

    printf("Original message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}