#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

// This array's length is equal to the English alphabet's length (0-25)
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                      1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void printGameTitle();
int computeScore(char word[]);
void printWinner(int scorePlayerOne, int scorePlayerTwo, char playerOneName[50], char playerTwoName[50]);
void waitForEnter();
void printPlayerScore(char playerName[50], int finalScore);
void getPlayerName(char playerName[], int playerNumber);
int multipleChoice(bool canCancel, const char *options[]);
void clearScreen();

#define OPTIONS_COUNT 2

int main(void)
{
    printGameTitle();

    const char *options[OPTIONS_COUNT] = {"START", "QUIT"};
    int choice = multipleChoice(true, options);

    if (strcmp(options[choice], "QUIT") == 0)
    {
        printf("Come back later!\n");
        return 1;
    }

    char playerOneName[50];
    char playerTwoName[50];

    getPlayerName(playerOneName, 1);
    getPlayerName(playerTwoName, 2);

    int scorePlayerOne = 0;
    int scorePlayerTwo = 0;
    int round = 1;
    while(round <= 3)
    {
        printf("Round %i\n", round); // Print round

        // Prompt players for words
        char playerOneInput[50];
        char playerTwoInput[50];

        printf("%s: ", playerOneName);
        scanf("%s", playerOneInput);

        printf("%s: ", playerTwoName);
        scanf("%s", playerTwoInput);
        printf("\n");

        // Compute the score of each word
        scorePlayerOne += computeScore(playerOneInput);
        scorePlayerTwo += computeScore(playerTwoInput);

        // Print current scores
        printPlayerScore(playerOneName, scorePlayerOne);
        printPlayerScore(playerTwoName, scorePlayerTwo);
        printf("\n");

        round++;
    }

    printWinner(scorePlayerOne, scorePlayerTwo, playerOneName, playerTwoName);

    printf("\nPress [Enter] key to exit.\n");
    waitForEnter();
}

// Prints Word Spitter title in ASCII art
void printGameTitle()
{
    printf("Welcome to...\n");
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

// Print the winner
void printWinner(int scorePlayerOne, int scorePlayerTwo, char playerOneName[50], char playerTwoName[50])
{
    if (scorePlayerOne > scorePlayerTwo)
    {
        printf("Result: %s wins!\n", playerOneName);
    }
    else if (scorePlayerOne < scorePlayerTwo)
    {
        printf("Result: %s wins!\n", playerTwoName);
    }
    else
    {
        printf("Result: It's a tie!\n");
    }
}

// Ask user for pressing enter
void waitForEnter()
{
    fflush(stdin); // clean stdin
    getchar(); // wait for ENTER
}

// Print score per player
void printPlayerScore(char playerName[50], int finalScore)
{
    printf("%s scored %i points. \n", playerName, finalScore);
}



void getPlayerName(char playerName[], int playerNumber)
{
    printf("Player %i, choose your Name: ", playerNumber);
    scanf("%s", playerName);
    printf("\n");
}

void clearScreen() {
    for (int i = 0; i < 50; i++)
        printf("\n");
}

int multipleChoice(bool canCancel, const char *options[]) {
    const int startX = 0;
    const int startY = 8;
    const int spacingPerLine = 14;

    int currentSelection = 0;
    int i;

    do {
        clearScreen(); // Clear the screen

        for (i = 0; i < OPTIONS_COUNT; i++) {
            printf("%*s", startX, ""); // Set cursor on the right position

            if(i == currentSelection)
                printf("\033[0;31m"); // Set red color

            printf("%s\n", options[i]);
            printf("\033[0m"); // Reset color
        }

        int key = _getch(); // Read the key from console

        switch (key) {
            case 224: // Recognize arrow keys
            case 0:
                key = _getch();
                switch (key) {
                    case 72: // Up arrow key
                        if (currentSelection > 0)
                            currentSelection--;
                        break;
                    case 80: // Down arrow key
                        if (currentSelection < OPTIONS_COUNT - 1)
                            currentSelection++;
                        break;
                }
                break;
            case 13: // Enter
                return currentSelection;
            case 27: // Escape
                if (canCancel)
                    return -1;
                break;
        }
    } while (1);

    return currentSelection;
}
