#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);
float check_grade(int letters, int words, int sentence);

int main(void)
{

    // get the text from user
    string text = get_string("Enter your text: ");

    // count the number of letters in the text
    int letters = count_letters(text);

    // count the number of words in the text
    int words = count_words(text);

    // count the number of sentence in the text
    int sentence = count_sentence(text);

    // check the grade for which the text is suitable
    float grade = check_grade(letters, words, sentence);

    // prints out the grade
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
        printf("Grade %i\n", (int) round(grade));
    }
}

int count_letters(string text)
{
    // TODO
    int spaces = 0;
    int symbols = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
        }

        else if (ispunct(text[i]))
        {
            symbols++;
        }
    }

    int letters = strlen(text) - spaces - symbols;
    return letters;
}

int count_words(string text)
{
    // TODO
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentence(string text)
{
    // TODO
    int sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}

float check_grade(int letters, int words, int sentence)
{
    // TODO
    float L = ((float) letters / (float) words) * (float) 100;
    float S = ((float) sentence / (float) words) * (float) 100;

    float avglet = (float) 0.0588 * (float) L;
    float avgsen = (float) 0.296 * (float) S;

    float index = avglet - avgsen - 15.8;
    return index;
}