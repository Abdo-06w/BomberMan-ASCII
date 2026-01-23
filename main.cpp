#include <iostream>
#include <curses.h>
#include "Globals.h"
#include "Menu.h"
#include "Player.h"
#include "Stanza.h"
#include "Render.h"
#include <cstring>
#include "Game.h"
using namespace std;


int main() {

    initscr();
    noecho();
    cbreak();


    int maxY,maxX;
    getmaxyx(stdscr, maxY, maxX);

    int startX = (maxX - X_GAME) / 2;
    int startY = (maxY - Y_GAME) / 2;



    WINDOW* test = newwin(Y_GAME, X_GAME, startY, startX);
    refresh();
    wrefresh(test);



    Game* g = new Game(test);
    g->addEnemy({4,4});
    g->addEnemy({17,5});


    int input;


    g->getRender()->display();

    nodelay(test, TRUE);

    do{

        g->update();


        input = wgetch(test);
        if (input != ERR) {
            g->getPlayer()->handleInput(input);
        }


        werase(test);
        g->renderGame();
        wrefresh(test);


    }while (input != 'x');



    getch();
    endwin();


    return 0;
}


// g++ *.cpp -o bomber -lpdcurses
// g++ *.cpp -o bomber -lncurses
