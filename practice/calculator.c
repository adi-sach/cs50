#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long dollars=1;
    while (true)
    {
        char c= get_char("Here's %li, Double it or give it to the next person\n", dollars );
        if (c =='y')
        {
            dollars *=2;
        }
        else
        {
            break;
        }
    }
}
