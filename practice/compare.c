#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x= get_int("Enter x \n");
    int y= get_int("Enter y \n");

    if (x>y)
    {
        printf("x is greater than y \n");
    }
    else if (x<y)
    {
        printf("y is greater than x \n");
    }
    else
    {
        printf("x and y are equal \n");

    }
}
