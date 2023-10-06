#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string getInput();
int countLetters(string text);
int countWords(string text);
int countSentences(string text);
int calculateIndex(int letters, int words, int sentences);
void printResult(int index);

int main(void)
{
    string text = getInput();

    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);
    int index = calculateIndex(letters, words, sentences);

    printResult(index);
}

string getInput()
{
    return get_string("Text: ");
}

int countLetters(string text)
{
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int countWords(string text)
{
    int words = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words + 1;
}

int countSentences(string text)
{
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

int calculateIndex(int letters, int words, int sentences)
{
    float factor = words / 100.0;

    float l = letters / factor;
    float s = sentences / factor;

    int index = round(0.0588 * l - 0.296 * s - 15.8);
    return index;
}

void printResult(int index)
{
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
