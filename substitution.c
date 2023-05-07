#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_key(string text);
void print_cipher(string text, string key);

int main(int argc, string argv[])
{

    // Checks if key provided or not
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // checks the validity of key provided
    bool check = valid_key(argv[1]);

    //  checks if the key provided is typed correctly without any spaces
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // if the key is correct prints the ciphertext
    else if (check == true)
    {
        string plaintext = get_string("plaintext:  ");
        print_cipher(plaintext, argv[1]);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


bool valid_key(string text)
{
    // checks the validity of key
    int count = 0;
    int check = 0;
    int loop = 1;
    char array[26];

    // checks the repetition of any character and all the characters are alphabets
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        array[i] = text[i];
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }

        for (int k = 0; k < loop; k++)
        {
            if (text[i] == array[k])
            {
                check++;
            }
        }
        loop++;
    }


    // if everything is right program returns true else returns false
    if (count == 26 && check == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void print_cipher(string text, string key)
{
    // prints the ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        // if the character is uppercase
        char c = text[i];
        if (isupper(c))
        {
            int u = text[i];
            u -= 65;
            char upper = toupper(key[u]);
            printf("%c", upper);
        }

        // if the character is lowercase
        else if (islower(c))
        {
            int l = text[i];
            l -= 97;
            char lower = tolower(key[l]);
            printf("%c", lower);
        }
        // if the character is not an alphabet
        else
        {
            printf("%c", text[i]);
        }
    }

    // prints a new line
    printf("\n");
}