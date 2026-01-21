
#include <iostream>
#include <curses.h>

#include "gioco.h"
#include "Menu.h"
#include "Player.h"
#include "Stanza.h"
#include "Render.h"

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




    Stanza *x = new Stanza(test,20,40);
    Bomba *b = new Bomba(0,0,'*',x);
    Player *p = new Player({0,0},b,x);
    Render *r = new Render(test,x);

    r->setBomba(b);
    r->setPlayer(p);
    r->setStanza(x);



    int input;

    r->renderPlayer();


    nodelay(test, TRUE);

    do{
        b->update();


        input = wgetch(test);
        if (input != ERR) {
            p->handleInput(input);
        }

        werase(test);
        r->display();
        wrefresh(test);


    }while (input != 'x');



    getch();
    endwin();


    return 0;
}


// g++ *.cpp -o bomber -lpdcurses
