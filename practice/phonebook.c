#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string names;
    string phones;
} person;

int main (void)
{
    person people[3];

    people[0].names="Justin";
    people[1].names="Martin";
    people[2].names="Bob";

    people[2].phones="+91-548431684";
    people[2].phones="+91-548787878";
    people[2].phones="+91-123456871";

    string name=get_string("Enter name: ");

    for (int i=0; i<3; i++)
    {
        if (strcmp(people[i].names, name)==0)
        {
            printf ("Phone: %s\n", people[i].phones);
            return 0;
        }
    }
    printf("Name not found\n");
}
