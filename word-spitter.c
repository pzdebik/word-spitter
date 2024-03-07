#include <stdio.h>
#include <ctype.h>
#include <string.h>

// This array's length is equal to the English alphabet's length (0-25)
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                      1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void printGameTitle();
int computeScore(char word[]);

int main(void)
{
    printGameTitle();

    // Prompt players for words
    char playerOneInput[50];
    char playerTwoInput[50];

    printf("Player 1: ");
    scanf("%s", playerOneInput);

    printf("Player 2: ");
    scanf("%s", playerTwoInput);

    // Compute the score of each word
    int scorePlayerOne = computeScore(playerOneInput);
    int scorePlayerTwo = computeScore(playerTwoInput);

    // Print scores
    printf("\nFinal scores: \n");
    printf("Player One scored %i points. \n", scorePlayerOne);
    printf("Player Two scored %i points. \n\n", scorePlayerTwo);

    // Print the winner
    if (scorePlayerOne > scorePlayerTwo)
    {
        printf("Result: Player 1 wins!\n");
    }
    else if (scorePlayerOne < scorePlayerTwo)
    {
        printf("Result: Player 2 wins!\n");
    }
    else
    {
        printf("Result: It's a tie!\n");
    }
}

// Prints Word Spitter title in ASCII art
void printGameTitle()
{

    printf("__      __              _        ___  _ __  _  _    _             \n"
                  "\\ \\    / / ___  _ _  __| |      / __|| '_ \\(_)| |_ | |_  ___  _ _ \n"
                  " \\ \\/\\/ / / _ \\| '_|/ _` |      \\__ \\| .__/| ||  _||  _|/ -_)| '_|\n"
                  "  \\_/\\_/  \\___/|_|  \\__/_|      |___/|_|   |_| \\__| \\__|\\___||_|  \n");
}

// Computes the final score using POINTS array
int computeScore(char word[])
{
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Every character of the passed word is turned to uppercase
        char upperedChar = toupper(word[i]);
        // Final score is the result of summing operation on every point obtained from the subtraction operation
        // Uppered char is subtracted from the first letter of the alphabet, which gives us the position of the letter in the alphabet
        if (isalpha(upperedChar))
        {
            score += POINTS[upperedChar - 'A'];
        }
    }
    return score;
}

