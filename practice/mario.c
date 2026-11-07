#include <stdio.h>

void print_rows(int n);

int main (void)
{
    //never change n
    const int n=3;
    print_rows(n);
}


void print_rows(int n)
{
    for (int i=0; i<n; i++)
    {
        printf("#");
    }
    printf("\n");
}
