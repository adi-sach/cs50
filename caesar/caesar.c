#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Invalid number of characters input\n");
        return 1;
    }

    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key_value = atoi(key);

    string plaintext = get_string("plaintext: ");

    char ciphertext[strlen(plaintext) + 1];

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            ciphertext[i] = (c - 'A' + key_value) % 26 + 'A';
        }
        else if (islower(c))
        {
            ciphertext[i] = (c - 'a' + key_value) % 26 + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
