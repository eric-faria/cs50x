#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(int argc, string argv[]);
int encipher(string plaintext, string key);

int main(int argc, string argv[])
{

    if (isValid(argc, argv))
    {
        return 1;
    }
    else
    {
        string key = argv[1];
        string text = get_string("plaintext: ");
        return encipher(text, key);
    }
}

int isValid(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        char character = argv[1][i];
        if (!isalpha(character))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        for (int j = 0; j < n; j++)
        {
            char aux = argv[1][j];
            if (toupper(character) == toupper(aux) && i != j)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

int encipher(string text, string key)
{
    int value;
    char character;
    char ciphertext[strlen(text)];

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        bool alphanumeric = isalpha(text[i]);

        if (alphanumeric && isupper(c))
        {
            value = c - 65;
            character = toupper(key[value]);
        }
        else if (alphanumeric && islower(c))
        {
            value = c - 97;
            character = tolower(key[value]);
        }
        else
        {
            character = c;
        }
        ciphertext[i] = character;
    }
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}
