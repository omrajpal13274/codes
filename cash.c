#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int cents;
    do
    {
        cents = get_int("Cents owed? ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int quarters = 0;
    int leftout = cents - 25;

    if (leftout >= 0)
    {
        quarters++;
        while (leftout >= 25)
        {
            leftout = leftout - 25;
            quarters++;
        }
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
    int dimes = 0;
    int leftout = cents - 10;

    if (leftout >= 0)
    {
        dimes++;
        while (leftout >= 10)
        {
            leftout = leftout - 10;
            dimes++;
        }
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
    int nickels = 0;
    int leftout = cents - 5;

    if (leftout >= 0)
    {
        nickels++;
        while (leftout >= 5)
        {
            leftout = leftout - 5;
            nickels++;
        }
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // TODO
    int pennies = 0;
    int leftout = cents - 1;

    if (leftout >= 0)
    {
        pennies++;
        while (leftout >= 1)
        {
            leftout = leftout - 1;
            pennies++;
        }
    }
    return pennies;
}
