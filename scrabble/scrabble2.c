#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_points(string p1, string p2);

int main (void)
{
    string p1= get_string("Player 1: ");
    string p2= get_string("Player 2: ");

    for (int i = 0; i < strlen(p1); i++)
    {
        p1[i] = tolower(p1[i]);
    }

    for (int i = 0; i < strlen(p2); i++)
    {
        p2[i] = tolower(p2[i]);
    }

    int i= check_points(p1,p2);
    if (i == 1)
    {
        printf("Player 1 wins!\n");
    }
    else if (i == -1)
    {
        printf("Player 2 wins!\n");
    }
    else if (i==0)
    {
        printf("Tie!\n");
    }
    else if (i==101)
    {
        printf("Some error occured\n");
    }
}

int check_points(string p1, string p2)
{
    int points1=0, points2=0;
    for (int i=0; i<strlen(p1);i++)
    {
        if (p1[i]== 'a' || p1[i]== 'e' || p1[i]== 'i' || p1[i]== 'l' || p1[i]== 'n' || p1[i]== 'o' || p1[i]== 'r' || p1[i]== 's' || p1[i]== 't' || p1[i]== 'u')
        {
            points1+=1;
        }
        else if (p1[i]== 'g' || p1[i]== 'd')
        {
            points1+=2;
        }
        else if (p1[i]== 'b' || p1[i]== 'c' || p1[i]== 'm' || p1[i]== 'p')
        {
            points1+=3;
        }
        else if (p1[i]== 'f'|| p1[i]== 'h' || p1[i]== 'v' || p1[i]== 'w' || p1[i]== 'y')
        {
            points1+=4;
        }
        else if (p1[i]== 'k')
        {
            points1+=5;
        }
        else if (p1[i]== 'j' || p1[i]== 'x')
        {
            points1+=8;
        }
        else if (p1[i]== 'q' || p1[i]== 'z')
        {
            points1+=10;
        }
    }
    for (int i=0; i<strlen(p2);i++)
    {
        if (p2[i]== 'a' || p2[i]== 'e' || p2[i]== 'i' || p2[i]== 'l' || p2[i]== 'n' || p2[i]== 'o' || p2[i]== 'r' || p2[i]== 's' || p2[i]== 't' || p2[i]== 'u')
        {
            points2+=1;
        }
        else if (p2[i]== 'g' || p2[i]== 'd')
        {
            points2+=2;
        }
        else if (p2[i]== 'b' || p2[i]== 'c' || p2[i]== 'm' || p2[i]== 'p')
        {
            points2+=3;
        }
        else if (p2[i]== 'f'|| p2[i]== 'h' || p2[i]== 'v' || p2[i]== 'w' || p2[i]== 'y')
        {
            points2+=4;
        }
        else if (p2[i]== 'k')
        {
            points2+=5;
        }
        else if (p2[i]== 'j' || p2[i]== 'x')
        {
            points2+=8;
        }
        else if (p2[i]== 'q' || p2[i]== 'z')
        {
            points2+=10;
        }
    }
    if (points1 > points2)
    {
        return 1;
    }
    else if (points2 > points1)
    {
        return -1;
    }
    else if (points1 == points2)
    {
        return 0;
    }
    else
    {
        return 101;
    }
}
