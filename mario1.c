#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_block(int n);

int main(void)
{

    // get the size from user
    int size = get_size();
    // print the pyramid
    print_block(size);

}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Height? ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_block(int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {

        // print the required number of spaces

        for (int k = n; k > count; k--)
        {
            printf(" ");
        }

        // print the required number of hashes

        for (int j = 0; j < count; j++)
        {
            printf("#");
        }

        printf("\n");
        count++;
    }
}