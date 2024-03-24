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
void startGame(int numberOfPlayers);
void waitForEnter();
void printPlayerScore(char playerName[50], int finalScore);
int multipleChoice(bool canCancel, const char *options[]);
void clearConsole();


#define OPTIONS_COUNT 4

int main(void)
{
    const char *options[OPTIONS_COUNT] = {"QUICK START", "GAME MODES", "HOW TO PLAY", "QUIT"};
    int choice = multipleChoice(true, options);
    char answer[2];

    if (strcmp(options[choice], "QUIT") == 0)
    {
        clearConsole();
        printf("Come back later!\n");
        return 0;
    }
    else if (strcmp(options[choice], "HOW TO PLAY") == 0)
    {
        clearConsole();
        printf("\nJust write something...\n");

        printf("\nDo you want to go back to the selection screen? (y/n): ");
        scanf("%s", answer);

        if (strcmp(answer, "y") == 0) {
            clearConsole();
            main();
        }
        else
        {
            clearConsole();
            printf("\nThen what don't you understand?\n");
            printf("Let's play!\n");
        }
    }
    else if (strcmp(options[choice], "GAME MODES") == 0)
    {
        char modeNumber[2];
        clearConsole();
        printf("1. Player vs Player\n");
        printf("2. Battle Royal\n");

        printf("\nChoose your mode (1-2): ");
        scanf("%s", modeNumber);

        if (strcmp(modeNumber, "1") == 0)
        {
            clearConsole();
            startGame(2);
        }
        else if (strcmp(modeNumber, "2") == 0)
        {
            clearConsole();
            startGame(10);
        }
        else
        {
            clearConsole();
            printf("Chosen mode doesn't exist. Try again.\n");
            printf("Click enter to proceed to the main screen.\n");
            waitForEnter();
            main();
        }
    }

    clearConsole();
    startGame(2);
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

void clearConsole() {
    printf("\033c"); // Reset all terminal settings to default
}

int multipleChoice(bool canCancel, const char *options[]) {
    const int startX = 0;

    int currentSelection = 0;
    int i;

    do {
        printGameTitle();
        printf("\n");
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
        clearConsole();
    } while (1);

    return currentSelection;
}

void startGame(int numberOfPlayers)
{
    // Define players
    char playerNames[numberOfPlayers][50];
    int scores[numberOfPlayers];

    // Get player's names
    for (int i = 0; i < numberOfPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", playerNames[i]);
        scores[i] = 0; // Initialize scores to 0
    }

    int round = 1;

    printf("\n");
    while (round <= 3)
    {
        printf("Round %i\n", round); // Print round

        // Get words from players
        char playerInputs[numberOfPlayers][50];
        for (int i = 0; i < numberOfPlayers; i++) {
            printf("%s: ", playerNames[i]);
            scanf("%s", playerInputs[i]);
        }
        printf("\n");

        // Count score per each word
        for (int i = 0; i < numberOfPlayers; i++) {
            scores[i] += computeScore(playerInputs[i]);
        }

        // Print current scores
        for (int i = 0; i < numberOfPlayers; i++) {
            printPlayerScore(playerNames[i], scores[i]);
        }
        printf("\n");

        round++;
    }

    // Print winner
    int maxScore = scores[0];
    int winnerIndex = 0;
    for (int i = 1; i < numberOfPlayers; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }
    printf("Winner: %s\n", playerNames[winnerIndex]);

    printf("\nPress [Enter] key to exit.\n");
    waitForEnter();
}
