#include <stdio.h>

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

