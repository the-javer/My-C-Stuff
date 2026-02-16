#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rps.h"

// The value of rock is 1
// The value of paper is 2
// The value of scissors is 3
int math, intchoice, compchoice, usrscore, compscore, games;
char usrchoice[9], ans;

int *mathptr = &math, *intptr = &intchoice, *compptr = &compchoice, *scrptr1 = &usrscore, *scrptr2 = &compscore, *gameptr = &games;
char *ansptr = &ans;
void allocate() {
    mathptr = malloc(sizeof(mathptr));
    intptr = malloc(sizeof(intptr));
    compptr = malloc(sizeof(compptr));
    ansptr = malloc(sizeof(ansptr));
    scrptr1 = malloc(sizeof(scrptr1));
    scrptr2 = malloc(sizeof(scrptr2));
    gameptr = malloc(sizeof(gameptr));
}

int main() {
    allocate();
    choice();
}

void score() {
    printf("Score:\nComputer: %i\nUser: %i\n\n", compscore, usrscore);
    if (usrscore==2&&compscore==0) {
        printf("You win!\n");
        leave();
    }
    else if (compscore==2&&usrscore==0) {
        printf("You lose\n");
        leave();
    }
    if (games >= 3) {
        if (usrscore > compscore) {
            printf("You win!\n");
            leave();
        }
        else if (usrscore < compscore) {
            printf("Computer wins\n");
            leave();
        }
        else {
            printf("The game has ended as a draw\n");
            leave();
        }
    }
    else {
        choice();
    }
}

void choice() {
    printf("Choose an object (Rock, paper, or scissors): ");
    scanf("%s", &usrchoice);
    if (usrchoice[0] == 'r'||'R') {
        intchoice = 1;
        logic();
    }
    else if (usrchoice[0] == 'p'||'P') {
        intchoice = 2;
        logic();
    }
    else if (usrchoice[0] == 's'||'S') {
        intchoice = 3;
        logic();
    }
    else {
        printf("Invalid input");
        leave();
    }
}

void logic() {
    srand(time(NULL));
    compchoice = (rand() % 3) + 1;

    math = intchoice + compchoice;

    if (usrchoice[0] == 'r'||'R') {
        switch (math) {
            case 3:
                printf("\nComputer chose paper, point for computer\n");
                compscore++;
                games++;
                score();
                break;
            case 4:
                printf("\nComputer chose scissors, point for you\n");
                usrscore++;
                games++;
                score();
                break;
            case 2:
                printf("\nComputer chose the same as you, no points\n");
                score();
                break;
            default:
                printf("An error has occured within the program");
                leave();
                break;
        }
    }

    if (usrchoice[0] == 'p'||'P') {
        switch (math) {
            case 3:
                printf("\nComputer chose rock, point for you\n");
                usrscore++;
                games++;
                score();
                break;
            case 5:
                printf("\nComputer chose scissors, point for computer\n");
                compscore++;
                games++;
                score();
                break;
            case 4:
                printf("\nComputer chose the same as you, no points\n");
                score();
                break;
            default:
                printf("An error has occured within the program");
                leave();
                break;
        }
    }

    if (usrchoice[0] == 's'||'S') {
        switch (math) {
            case 4:
                printf("\nComputer chose rock, point for computer\n");
                compscore++;
                games++;
                score();
                break;
            case 5:
                printf("\nComputer chose paper, point for you\n");
                usrscore++;
                games++;
                score();
                break;
            case 6:
                printf("\nComputer chose the same as you, no points\n");
                score();
                break;
            default:
                printf("An error has occured within the program");
                leave();
                break;
        }
    }
}

void leave() {
    printf("\nWould you like to play again? y/n: ");
    scanf("\n%c", &ans);
    switch(ans) {
        case 'Y':
        reset();
        choice();
        break;

        case 'y':
        reset();
        choice();
        break;

        case 'N':
        deallocate();
        exit(0);
        break;

        case 'n':
        deallocate();
        exit(0);
        break;

        default:
        printf("Invalid input");
        leave();
    }
}

void reset() {
    usrscore = 0;
    compscore = 0;
    games = 0;
    printf("\e[1;1H\e[2J");
}

void deallocate() {
    free(mathptr);
    free(intptr);
    free(compptr);
    free(ansptr);
    free(scrptr1);
    free(scrptr2);
    free(gameptr);
    mathptr = NULL;
    intptr = NULL;
    compptr = NULL;
    ansptr = NULL;
    scrptr1 = NULL;
    scrptr2 = NULL;
    gameptr = NULL;
    usrchoice[0] = '\0';
}