#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (n <= 0 || n > 8);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = i; k > 0; k--)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
