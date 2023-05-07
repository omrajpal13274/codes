#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{

    // get the size from user
    int n = get_size();

    // print the grid
    print_grid(n);
}





int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size? ");
    }

    while (n < 1 || n > 8);
    return n;
}

void print_grid(int size)
{
    int count = 1;

    for (int i = 0; i < size; i++)
    {
        // print the required number of spaces
        for (int j = size; j > count; j--)
        {
            printf(" ");
        }

        // print the required number of hashes for first pyramid
        for (int k = 0; k < count; k++)
        {
            printf("#");
        }

        // print the gap
        printf("  ");

        // print the required number of hashes for second pyramid
        for (int l = 0; l < count; l++)
        {
            printf("#");
        }

        printf("\n");
        count++;
    }
}