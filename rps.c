#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rps.h"

// The value of rock is 1
// The value of paper is 2
// The value of scissors is 3
int math, intchoice, compchoice;
char usrchoice, ans;

int *mathptr = &math, *intptr = &intchoice, *compptr = &compchoice;
char *usrptr = &usrchoice, *ansptr = &ans;

void allocate() {
    mathptr = &math;
    usrptr = &usrchoice;
    intptr = &intchoice;
    compptr = &compchoice;
    ansptr = &ans;
    mathptr = malloc(sizeof(mathptr));
    usrptr = malloc(sizeof(usrptr));
    intptr = malloc(sizeof(intptr));
    compptr = malloc(sizeof(compptr));
    ansptr = malloc(sizeof(ansptr));
}

int main() {
    allocate();
    choice();
}

void choice() {
    printf("Choose a object by typing the first letter in its name: ");
    scanf("\n%c", &usrchoice);

    switch (usrchoice) {
     case 'r':
        intchoice = 1;
        logic();
        break;
    case 'p':
        intchoice = 2;
        logic();
        break;
    case 's':
        intchoice = 3;
        logic();
        break;
    default:
        printf("Invalid input");
        leave();
}
}

void logic() {
    srand(time(NULL));
    compchoice = (rand() % 3) + 1;

    math = intchoice + compchoice;

    if (usrchoice == 'r') {
        switch (math) {
            case 3:
                printf("Computer chose paper, you lose");
                leave();
                break;
            case 4:
                printf("Computer chose scissors, you win");
                leave();
                break;
            case 2:
                printf("Computer chose the same as you, it is a draw");
                leave();
                break;
            default:
                printf("An error has occured within the program");
                leave();
                break;
        }
    }

    if (usrchoice == 'p') {
        switch (math) {
            case 3:
                printf("Computer chose rock, you win");
                leave();
                break;
            case 5:
                printf("Computer chose scissors, you lose");
                leave();
                break;
            case 4:
                printf("Computer chose the same as you, it is a draw");
                leave();
                break;
            default:
                printf("An error has occured within the program");
                leave();
                break;
        }
    }

    if (usrchoice == 's') {
        switch (math) {
            case 4:
                printf("Computer chose rock, you lose");
                leave();
                break;
            case 5:
                printf("Computer chose paper, you win");
                leave();
                break;
            case 6:
                printf("Computer chose the same as you, it is a draw");
                leave();
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

    if (ans == 'y') {
        choice();
    }
    if (ans == 'n') {
        deallocate();
        exit(0);
    }
    else {
        printf("Invalid input");
        leave();
    }
}

void deallocate() {
    free(mathptr);
    free(usrptr);
    free(intptr);
    free(compptr);
    free(ansptr);
    mathptr = NULL;
    usrptr = NULL;
    intptr = NULL;
    compptr = NULL;
    ansptr = NULL;
}
