#ifndef BOMBERMAN_CLASSIFICA_H
#define BOMBERMAN_CLASSIFICA_H
#include <curses.h>
#include "Menu.h"


struct Giocatore {
    const char* name;
    int score;
};
typedef Giocatore *giocatore;


class Menu;

class Classifica {
    protected:
    WINDOW* win;
    Menu* menu;

    int numBestPlayers;
    int numCurrPlayers = 0;
    giocatore* players;




    public:

    Classifica(WINDOW *w,Menu* m);

    void addPlayer(const char* name, int score);
    void sortPlayers();

    void draw();
    void drawTopPlayers();
    void btnClassifica();

    void showNumInput();

    bool isNumValid();

    void showClassifica();




};


#endif //BOMBERMAN_CLASSIFICA_H