#include <ctype.h>
#include <stdio.h>
#include <string.h>

void printGameTitle();

int main(void)
{
    printGameTitle();
}

// Prints Word Spitter title in ASCII art
void printGameTitle()
{
    printf(" ▄     ▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄   ▄▄▄▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄   \n");
    printf("█ █ ▄ █ █       █   ▄  █ █      █   █       █       █   █       █       █       █   ▄  █  \n");
    printf("█ ██ ██ █   ▄   █  █ █ █ █  ▄    █  █  ▄▄▄▄▄█    ▄  █   █▄     ▄█▄     ▄█    ▄▄▄█  █ █ █  \n");
    printf("█       █  █ █  █   █▄▄█▄█ █ █   █  █ █▄▄▄▄▄█   █▄█ █   █ █   █   █   █ █   █▄▄▄█   █▄▄█▄ \n");
    printf("█       █  █▄█  █    ▄▄  █ █▄█   █  █▄▄▄▄▄  █    ▄▄▄█   █ █   █   █   █ █    ▄▄▄█    ▄▄  █\n");
    printf("█   ▄   █       █   █  █ █       █   ▄▄▄▄▄█ █   █   █   █ █   █   █   █ █   █▄▄▄█   █  █ █\n");
    printf("█▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄█  █▄█▄▄▄▄▄▄█   █▄▄▄▄▄▄▄█▄▄▄█   █▄▄▄█ █▄▄▄█   █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄█  █▄█\n");
}

