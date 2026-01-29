#include <iostream>
#include <curses.h>
#include <cstring>
#include "Menu.h"
#include "Globals.h"
#include "Classifica.h"
#include "GameManager.h"

using namespace std;


Menu::Menu(WINDOW *w) {
    win = w;
    classifica = new Classifica(win,this);
    gameManager = new GameManager(win,this);
    keypad(win, TRUE);
}

Classifica* Menu::getClassifica() {
    return classifica;
}

GameManager* Menu::getGameManager() {
    return gameManager;
}


void Menu::drawMenu() {
    noecho();

    box(win,0,0);

    const char* gameName = "BOMBERMAN ASCII";
    int nameX = (X_GAME - strlen(gameName)) / 2;
    int nameY = 5;

    wattron(win, A_BOLD);
    mvwprintw(win, nameY, nameX,"%s", gameName);
    wattroff(win, A_BOLD);

    const char* choices[] = {"Nuova Partita" , "Classifica", "Esci"};
    int n_choices = sizeof(choices)/sizeof(choices[0]);

    int highlight = 0;
    int choice;

    while (true) {

        for (int i = 0; i < n_choices; i++) {
            if (i == highlight) wattron(win, A_REVERSE);
            mvwprintw(win, 10 + i * 3, (X_GAME - strlen(choices[i])) / 2, "%s", choices[i]);
            if (i == highlight) wattroff(win, A_REVERSE);
        }
        wrefresh(win);

        choice = wgetch(win);

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

        if (choice == 10 || choice == KEY_ENTER) {
            if (strcmp(choices[highlight], "Nuova Partita") == 0)gameManager->enterName();
            if (strcmp(choices[highlight], "Classifica") == 0)classifica->showNumInput();
            if (strcmp(choices[highlight], "Esci") == 0) {
                endwin();
                exit(0);
            }

        }

    }
}


void Menu::showMenu() {
    werase(win);
    drawMenu();
    wrefresh(win);
}
