#include <iostream>
#include <curses.h>
#include <cstring>
#include "Menu.h"
#include "gioco.h"

using namespace std;



void mostraMenu() {

    int maxY,maxX;
    getmaxyx(stdscr, maxY, maxX);

    int startX = (maxX - X_GAME) / 2;
    int startY = (maxY - Y_GAME) / 2;

    if (startX < 0) startX = 0;
    if (startY < 0) startY = 0;

    WINDOW* menuWin = newwin(Y_GAME, X_GAME, startY, startX);
    refresh();
    box(menuWin, 0, 0);
    wrefresh(menuWin);

    const char* gameName = "BOMBERMAN ASCII";
    int nameX = (X_GAME - strlen(gameName)) / 2;
    int nameY = 5;

    wattron(menuWin, A_BOLD);
    mvwprintw(menuWin, nameY, nameX, gameName);
    wattroff(menuWin, A_BOLD);

    keypad(menuWin, true);

    const char* choices[] = {"Nuova Partita" , "Classifica", "Esci"};
    int n_choices = sizeof(choices)/sizeof(choices[0]);

    int highlight = 0;
    int choice;

    while (true) {

        for (int i = 0; i < n_choices; i++) {
            if (i == highlight) wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, 10 + i * 3, (X_GAME - strlen(choices[i])) / 2, "%s", choices[i]);
            if (i == highlight) wattroff(menuWin, A_REVERSE);
        }
        wrefresh(menuWin);

         choice = wgetch(menuWin);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) highlight = n_choices-1;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight >= n_choices) highlight = 0;
                break;
            default:
                break;
        }

        if (choice == 10) {
            if (strcmp(choices[highlight], "Esci") == 0)break;
            //....
        }

    }





}
