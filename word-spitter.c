#include <stdio.h>

// This array's length is equal to the English alphabet's length (0-25)
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                      1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void printGameTitle();

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
}

// Prints Word Spitter title in ASCII art
void printGameTitle()
{

    printf("__      __              _        ___  _ __  _  _    _             \n"
                  "\\ \\    / / ___  _ _  __| |      / __|| '_ \\(_)| |_ | |_  ___  _ _ \n"
                  " \\ \\/\\/ / / _ \\| '_|/ _` |      \\__ \\| .__/| ||  _||  _|/ -_)| '_|\n"
                  "  \\_/\\_/  \\___/|_|  \\__/_|      |___/|_|   |_| \\__| \\__|\\___||_|  \n");
}

