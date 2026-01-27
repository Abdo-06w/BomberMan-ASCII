#include <iostream>
#include <curses.h>
#include "Globals.h"
#include "Menu.h"
#include "Player.h"
#include "Stanza.h"
#include "Render.h"
#include <cstring>
#include "Game.h"
#include "Classifica.h"
#include "Mappa.h"
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




    Mappa* m = new Mappa(mainWin);
    Game* currentGame = m->getCurrentGame();


    int input;

    currentGame->getRender()->display();
    currentGame->getRender()->renderTime(m);
    nodelay(mainWin, TRUE);

    do{

        if (m->getTimer()->getTime() <= 0)break;

        m->update(currentGame->getPlayer());
        currentGame = m->getCurrentGame();

        input = wgetch(mainWin);
        if (input != ERR) {
            currentGame->getPlayer()->handleInput(input);
        }

        currentGame->update();



        werase(mainWin);
        currentGame->renderGame();
        currentGame->getRender()->renderTime(m);
        wrefresh(mainWin);


    }while (input != 'x');












    getch();
    endwin();

    return 0;
}


// g++ *.cpp -o bomber -lpdcurses
// g++ *.cpp -o bomber -lncurses
