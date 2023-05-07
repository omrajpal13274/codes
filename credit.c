#include <cs50.h>
#include <stdio.h>

long get_cardnum();
void print_type(long number, bool validity);
bool check_cardnum(long number);

int main(void)
{

    // ask the user for card number
    bool validity = false;
    long cardnum = get_cardnum();

    // check the validity of card number
    validity = check_cardnum(cardnum);

    // print which company card it it
    print_type(cardnum, validity);


}


long get_cardnum()
{
    // ask the user to enter the card number
    long number = get_long("Enter card number: ");
    // return the value to use it
    return number;
}

void print_type(long number, bool validity)
{
    // if a valid card number tell the type of card
    if (validity == true)
    {
        int a = number / 1000000000000;
        int b = number / 1000000000000000;
        int c = number / 10000000000000;
        int d = number / 100000000000000;

        if (a == 4 || b == 4)
        {
            // print the card is a VISA card
            printf("VISA\n");
        }
        else if (c == 34 || c == 37)
        {
            // print the card is a AMEX card
            printf("AMEX\n");
        }
        else if (d == 51 || d == 52 || d == 53 || d == 54 || d == 55)
        {
            // print the card is a MASTERCARD
            printf("MASTERCARD\n");
        }
        else
        {
            // print the card is INVALID
            printf("INVALID\n");
        }
    }

    // if not valid print invalid
    else
    {
        printf("INVALID\n");
    }
}


bool check_cardnum(long number)
{

    int i = number / 1000000000000;
    int j = number / 100000000000000;
    int k = number / 1000000000000000;

    long multidigit = 100;
    long multisum = 0;
    long digit = 10;
    long sum = 0;

    // if the card number is 13 digits run the following algorithm

    if (i < 10 && i > 0)
    {

        for (int x = 0; x < 6; x++)
        {
            // sum the alternate digits and multiply them by 2
            int newsum = (((number % multidigit) / (multidigit / 10)) * 2);
            if (newsum < 10)
            {
                multisum += newsum;
                multidigit *= 100;
            }

            else
            {
                newsum = ((newsum / 10) + (newsum % 10));
                multisum += newsum;
                multidigit *= 100;
            }

        }

        for (int y = 0; y < 7; y++)
        {
            // sum the other leftout digits
            int sums = (number % digit) / (digit / 10);
            sum += sums;
            digit *= 100;
        }

        // add both the sums
        sum = sum + multisum;

    }

    // if the card number is 15 digits run the following algorithm
    else if (j < 10 && j > 0)
    {

        for (int x = 0; x < 7; x++)
        {
            // sum all the alternate digits and multiply them by 2
            int newsum = (((number % multidigit) / (multidigit / 10)) * 2);
            if (newsum < 10)
            {
                multisum += newsum;
                multidigit *= 100;
            }

            else
            {
                newsum = ((newsum / 10) + (newsum % 10));
                multisum += newsum;
                multidigit *= 100;
            }

        }

        for (int y = 0; y < 8; y++)
        {
            // sum all the other leftout digits
            int sums = (number % digit) / (digit / 10);
            sum += sums;
            digit *= 100;
        }

        // add both of the sums
        sum = sum + multisum;

    }

    // if the card number is 16 digits run the following algorithm
    else if (k < 10 && k > 0)
    {

        for (int x = 0; x < 8; x++)
        {
            // sum all the alternate digits and multiply them by 2
            int newsum = (((number % multidigit) / (multidigit / 10)) * 2);
            if (newsum < 10)
            {
                multisum += newsum;
                multidigit *= 100;
            }

            else
            {
                newsum = ((newsum / 10) + (newsum % 10));
                multisum += newsum;
                multidigit *= 100;
            }

        }

        for (int y = 0; y < 8; y++)
        {
            // sum all the other leftout digits
            int sums = (number % digit) / (digit / 10);
            sum += sums;
            digit *= 100;
        }

        // add both the sums
        sum = sum + multisum;

    }
    else
    {
        return false;
    }

    // check whether the value is valid or not and return it to use
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}