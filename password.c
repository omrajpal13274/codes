// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int check = 0;
    int nul = 0;

    while (password[nul] != '\0')
    {
        nul++;
    }

    for(int i = 0; password[i] != '\0'; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            check++;
            i = nul;
        }
    }

    for(int j = 0; password[j] != '\0'; j++)
    {
        if(password[j] >= 'A' && password[j] <= 'Z')
        {
            check++;
            j = nul;
        }
    }

    for(int k = 0; password[k] != '\0'; k++)
    {
        if(password[k] >= '0' && password[k] <= '9')
        {
            check++;
            k = nul;
        }
    }

    for(int l = 0; password[l] != '\0'; l++)
    {
        if((password[l] >= '!' && password[l] <= '/') || (password[l] >= ':' && password[l] <= '@') || (password[l] >= '[' && password[l] <= '`') || (password[l] >= '{' && password[l] <= '~'))
        {
            check++;
            l = nul;
        }
    }

    if(check == 4)
    {
        return true;
    }
    else
    {
    return false;
    }
}