#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string get_winner(int scoreP1, int scoreP2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("%s", get_winner(score1, score2));
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int ascii = toupper(word[i]);
        if (ascii >= 65 && ascii <= 90)
        {
            score += POINTS[ascii - 65];
        }
    }
    return score;
}

string get_winner(int scoreP1, int scoreP2)
{
    if (scoreP1 > scoreP2)
    {
        return "Player 1 wins!";
    }
    else if (scoreP2 > scoreP1)
    {
        return "Player 2 wins!";
    }
    else
    {
        return "Tie!";
    }
}
