#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "rps.h"

// The value of rock is 1
// The value of paper is 2
// The value of scissors is 3
int math, intchoice, compchoice, usrscore, compscore, games;
char usrchoice, ans;

int *mathptr = &math, *intptr = &intchoice, *compptr = &compchoice, *scrptr1 = &usrscore, *scrptr2 = &compscore, *gameptr = &games;
char *ansptr = &ans, *usrptr = &usrchoice;

WINDOW *usrscrwin, *compscrwin, *outwin;

void allocate() {
    mathptr = malloc(sizeof(mathptr));
    intptr = malloc(sizeof(intptr));
    compptr = malloc(sizeof(compptr));
    ansptr = malloc(sizeof(ansptr));
    scrptr1 = malloc(sizeof(scrptr1));
    scrptr2 = malloc(sizeof(scrptr2));
    gameptr = malloc(sizeof(gameptr));
    usrptr = malloc(sizeof(usrptr));
}

int main(void) {
    allocate();
    initscr();
    raw();
    noecho();
    refresh();
    usrscrwin = newwin(3, 15, 0, 0);
    compscrwin = newwin(3, 15, 3, 0);
    outwin = newwin(3, 100, 6, 0);
    wclear(usrscrwin);
    wclear(compscrwin);
    mvwprintw(usrscrwin, 1, 1, "You: %d", usrscore);
    mvwprintw(compscrwin, 1, 1, "Computer: %d", compscore);
    wrefresh(usrscrwin);
    wrefresh(compscrwin);
    choice();
}

void score() {
    wclear(outwin);
    wclear(usrscrwin);
    wclear(compscrwin);
    mvwprintw(usrscrwin, 1, 1, "You: %d", usrscore);
    mvwprintw(compscrwin, 1, 1, "Computer: %d", compscore);
    wrefresh(usrscrwin);
    wrefresh(compscrwin);
    wrefresh(outwin);
    if (usrscore==2&&compscore==0) {
        mvwprintw(outwin, 1, 1, "You win!");
        wrefresh(outwin);
        sleep(1);
        leave();
    }
    else if (compscore==2&&usrscore==0) {
        mvwprintw(outwin, 1, 1, "You lose");
        wrefresh(outwin);
        sleep(1);
        leave();
    }
    if (games >= 3) {
        if (usrscore > compscore) {
            mvwprintw(outwin, 1, 1, "You win!");
            wrefresh(outwin);
            sleep(1);
            leave();
        }
        else if (usrscore < compscore) {
            mvwprintw(outwin, 1, 1, "Computer wins");
            wrefresh(outwin);
            sleep(1);
            leave();
        }
        else {
            mvwprintw(outwin, 1, 1, "The game has ended as a draw");
            wrefresh(outwin);
            sleep(1);
            leave();
        }
    }
    else {
        choice();
    }
}

void choice() {
    wclear(outwin);
    mvwprintw(outwin, 1, 1, "Choose an object by pressing the first letter of its name (r, p, or s)");
    wrefresh(outwin);
    usrchoice = getch();

    switch (usrchoice) {
        // if it equals r
        case 114:
        intchoice = 1;
        logic();
        break;
        // if it equals p
        case 112:
        intchoice = 2;
        logic();
        break;
        // if it equals s
        case 115:
        intchoice = 3;
        logic();
        break;
        // if it equals x (for exiting)
        case 120:
        wclear(outwin);
        mvwprintw(outwin, 1, 1, "Are you sure you want to exit? y/n");
        wrefresh(outwin);
        ans = getchar();
        switch (ans) {
            case 121:
            deallocate();
            endwin();
            exit(0);
            break;

            case 110:
            choice();
            break;
        }
        break;

        default:
        wclear(outwin);
        mvwprintw(outwin, 1, 1, "Invalid input");
        wrefresh(outwin);
        sleep(1);
        choice();
    }
}

void logic() {
    wclear(outwin);
    srand(time(NULL));
    compchoice = (rand() % 3) + 1;

    math = intchoice + compchoice;

    if (usrchoice == 114) {
        switch (math) {
            case 3:
                mvwprintw(outwin, 1, 1, "Computer chose paper, point for computer");
                wrefresh(outwin);
                compscore++;
                games++;
                sleep(1);
                score();
                break;
            case 4:
                mvwprintw(outwin, 1, 1, "Computer chose scissors, point for you");
                wrefresh(outwin);
                usrscore++;
                games++;
                sleep(1);
                score();
                break;
            case 2:
                mvwprintw(outwin, 1, 1, "Computer chose the same as you, no points");
                wrefresh(outwin);
                sleep(1);
                score();
                break;
            default:
                mvwprintw(outwin, 1, 1, "An error has occured within the program");
                wrefresh(outwin);
                sleep(1);
                leave();
                break;
        }
    }

    if (usrchoice == 112) {
        switch (math) {
            case 3:
                mvwprintw(outwin, 1, 1, "Computer chose rock, point for you");
                wrefresh(outwin);
                usrscore++;
                games++;
                sleep(1);
                score();
                break;
            case 5:
                mvwprintw(outwin, 1, 1, "Computer chose scissors, point for computer");
                wrefresh(outwin);
                compscore++;
                games++;
                sleep(1);
                score();
                break;
            case 4:
                mvwprintw(outwin, 1, 1, "Computer chose the same as you, no points");
                wrefresh(outwin);
                sleep(1);
                score();
                break;
            default:
                mvwprintw(outwin, 1, 1, "An error has occured within the program");
                wrefresh(outwin);
                sleep(1);
                leave();
                break;
        }
    }

    if (usrchoice == 115) {
        switch (math) {
            case 4:
                mvwprintw(outwin, 1, 1, "Computer chose rock, point for computer");
                wrefresh(outwin);
                compscore++;
                games++;
                sleep(1);
                score();
                break;
            case 5:
                mvwprintw(outwin, 1, 1, "Computer chose paper, point for you");
                wrefresh(outwin);
                usrscore++;
                games++;
                sleep(1);
                score();
                break;
            case 6:
                mvwprintw(outwin, 1, 1, "Computer chose the same as you, no points");
                wrefresh(outwin);
                sleep(1);
                score();
                break;
            default:
                mvwprintw(outwin, 1, 1, "An error has occured within the program");
                wrefresh(outwin);
                sleep(1);
                leave();
                break;
        }
    }
}

void leave() {
    wclear(outwin);
    mvwprintw(outwin, 1, 1, "Would you like to play again? y/n");
    wrefresh(outwin);
    ans = getch();
    switch(ans) {
        // if it equals y
        case 121:
        reset();
        choice();
        break;
        // if it equals n
        case 110:
        deallocate();
        endwin();
        exit(0);

        default:
        wclear(outwin);
        mvwprintw(outwin, 1, 1, "Invalid input");
        wrefresh(outwin);
        sleep(1);
        leave();
    }
}

void reset() {
    usrscore = 0;
    compscore = 0;
    games = 0;
    wclear(usrscrwin);
    wclear(compscrwin);
    mvwprintw(usrscrwin, 1, 1, "You: %d", usrscore);
    mvwprintw(compscrwin, 1, 1, "Computer: %d", compscore);
    wrefresh(usrscrwin);
    wrefresh(compscrwin);
}

void deallocate() {
    free(mathptr);
    free(intptr);
    free(compptr);
    free(ansptr);
    free(scrptr1);
    free(scrptr2);
    free(gameptr);
    free(usrptr);
    mathptr = NULL;
    intptr = NULL;
    compptr = NULL;
    ansptr = NULL;
    scrptr1 = NULL;
    scrptr2 = NULL;
    gameptr = NULL;
    usrptr = NULL;
    delwin(usrscrwin);
    delwin(compscrwin);
    delwin(outwin);
}