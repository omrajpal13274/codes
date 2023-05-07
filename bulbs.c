#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    int state[8];

    // Ask the user for text
    string text = get_string("Text: ");

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        // Get the number from char
        int number = text[i];
        int k = 0;

        while (k < BITS_IN_BYTE)
        {
            // convert it into binary number
            if (number % 2 == 0)
            {
                // bulb is off
                state[k] = 0;
                number /= 2;
                k++;
            }
            else
            {
                // bulb is on
                state[k] = 1;
                number /= 2;
                k++;
            }

        }
        // print the bulbs
        for (int l = 7; l >= 0; l--)
        {
            print_bulb(state[l]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
