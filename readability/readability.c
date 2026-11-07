#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters (string text);
int count_words (string text);
int count_sentences (string text);


int main (void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    if ( letters == 0 )
    {
        printf("The code does not contain any letters.\n");
        return 1;
    }
    if ( words == 0 )
    {
        printf("The code does not contain any words.\n");
        return 1;
    }

    float l = ((float)letters/words)*100.00;
    float s = ((float) sentences/words)*100.00;

    float index = (0.0588 * l - 0.296 * s - 15.8);
    int grade = (int)round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters (string text)
{
    int letters=0;
    int x = strlen(text);
    for (int i = 0; i < x; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words (string text)
{
    int words = 1;
    int x = strlen(text);
    for (int i = 0; i < x; i++)
    {
            if (isspace(text[i]))
            {
            words++;
            }
    }
    return words;
}

int count_sentences (string text)
{
    int sentences = 0;
    int x = strlen(text);
    for (int i = 0; i < x; i++)
    {
        if (text[i]=='.' || text[i]=='?' || text[i]=='!')
        {
            sentences++;
        }
    }
    return sentences;
}
