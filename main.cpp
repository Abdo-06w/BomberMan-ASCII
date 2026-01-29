#include <iostream>
#include <curses.h>
#include "Globals.h"
#include "Menu.h"
#include "Player.h"
#include <cstring>

using namespace std;

int main() {

    initscr();
    initGlobals();
    noecho();
    cbreak();
    curs_set(0);

    start_color();
    use_default_colors();

    int muroDistruttibileBg;
    int esplosioneBg;
    int muroinDistruttibileBg;
    int portaBg;


    if (COLORS >= 256) {
        muroDistruttibileBg = 244;          // grigio chiaro
        esplosioneBg = 196;                 // rosso brillante
        muroinDistruttibileBg = COLOR_WHITE;
        portaBg = 94;                       // marrone
    } else {
        muroDistruttibileBg = COLOR_CYAN;
        esplosioneBg = COLOR_RED;
        muroinDistruttibileBg = COLOR_BLUE;
        portaBg = COLOR_YELLOW;
    }

    init_pair(1, COLOR_BLACK, COLOR_BLACK);                          // pavimento
    init_pair(2, muroinDistruttibileBg, muroinDistruttibileBg);      // muri indistruttibili
    init_pair(3, muroDistruttibileBg, muroDistruttibileBg);          // muro distruttibili
    init_pair(4, esplosioneBg, esplosioneBg);                        // esplosione
    init_pair(5, COLOR_RED, COLOR_BLACK);                            // nemici
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);                         // items
    init_pair(7, COLOR_GREEN, COLOR_BLACK);                          // player
    init_pair(9, COLOR_RED, COLOR_BLACK);                             // bomba
    init_pair(10, portaBg, portaBg);                                  // porta



    WINDOW* mainWin = newwin(Y_GAME, X_GAME, startMainWinY, startMainWinX);
    refresh();
    box(mainWin, 0, 0);
    wrefresh(mainWin);

    Menu*m = new Menu(mainWin);

    m->showMenu();


    getch();
    endwin();

    return 0;
}

