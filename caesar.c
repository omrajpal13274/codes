#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void changetocipher(string plaintext, int key);
bool is_digit(string key);

int main(int argc, string argv[])
{

    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // initialize the boolean variable
    bool check = is_digit(argv[1]);

    // check if the key is provided or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

    // if key provided ask the user for text and print the ciphertext
    else if (check == true)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext:  ");
        changetocipher(plaintext, key);
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool is_digit(string key)
{
    int count = 0;
    // check whether key is only digits
    for (int i = 0; i < strlen(key); i++)
    {

        if (key[i] >= '0' && key[i] <= '9')
        {
            count++;
        }
    }

    // if key is digits return true;
    if (count == strlen(key))
    {
        return true;
    }

    // is key is not digits return false;
    else
    {
        return false;
    }
}

void changetocipher(string plaintext, int key)
{
    // prints ciphertext
    printf("ciphertext: ");

    // change to ciphertext
    for (int i = 0, j = strlen(plaintext); i < j; i++)
    {

        // if the char is upper character do this
        if (isupper(plaintext[i]))
        {
            char C = plaintext[i] - 65;
            C = (C + key) % 26;
            char cipher = C - (plaintext[i] - 65);
            printf("%c", plaintext[i] + cipher);
        }

        // if the char is lower character do this
        else if (islower(plaintext[i]))
        {
            char c = plaintext[i] - 97;
            c = (c + key) % 26;
            char Cipher = c - (plaintext[i] - 97);
            printf("%c", plaintext[i] + Cipher);
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}