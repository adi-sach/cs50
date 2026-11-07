#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_points(string p);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    for (int i = 0; i < strlen(p1); i++)
    {
        p1[i] = tolower(p1[i]);
    }

    for (int i = 0; i < strlen(p2); i++)
    {
        p2[i] = tolower(p2[i]);
    }

    int P1 = check_points(p1);
    int P2 = check_points(p2);

    if (P1 > P2)
    {
        printf("Player 1 wins!\n");
    }
    else if (P1 < P2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!");
    }
}

int check_points(string p)
{
    int points = 0;
    int str_len = strlen(p);
    for (int i = 0; i < str_len; i++)
    {
        if (p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'l' || p[i] == 'n' ||
            p[i] == 'o' || p[i] == 'r' || p[i] == 's' || p[i] == 't' || p[i] == 'u')
        {
            points += 1;
        }
        else if (p[i] == 'g' || p[i] == 'd')
        {
            points += 2;
        }
        else if (p[i] == 'b' || p[i] == 'c' || p[i] == 'm' || p[i] == 'p')
        {
            points += 3;
        }
        else if (p[i] == 'f' || p[i] == 'h' || p[i] == 'v' || p[i] == 'w' || p[i] == 'y')
        {
            points += 4;
        }
        else if (p[i] == 'k')
        {
            points += 5;
        }
        else if (p[i] == 'j' || p[i] == 'x')
        {
            points += 8;
        }
        else if (p[i] == 'q' || p[i] == 'z')
        {
            points += 10;
        }
    }
    return points;
}
