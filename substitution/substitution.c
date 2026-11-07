#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( int argc, string argv[] )
{


    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int key_length = strlen(key);

    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            key[i] = tolower(key[i]);
        }
    }

    for (int i=0; i< key_length; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key [j])
            {
                printf("Key must contain 26 unique alphabetic characters.\n");
                return 1;
            }
        }
    }



    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext) +1];

    for ( int i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext [i];
        if (isalpha(ch))
        {
            ch = tolower(ch);
            int c = ch - 'a' + 1 - 1;
            if (isupper(plaintext[i]))
            {
                ciphertext[i]=toupper(key[c]);
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i]=(key[c]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n" , ciphertext);
    return 0;
}
