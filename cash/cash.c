// Give change to the customer in the most efficient manner
// 25, 10, 5, 1
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);
    int count = 0;
    while (n >= 25)
    {
        n = n - 25;
        count++;
    }
    while (n < 25 && n >= 10)
    {
        n = n - 10;
        count++;
    }
    while (n < 10 && n >= 5)
    {
        n = n - 5;
        count++;
    }
    while (n < 5 && n >= 1)
    {
        n = n - 1;
        count++;
    }
    printf("%i\n", count);
}
