#ifndef BOMBERMAN_GAMEMANAGER_H
#define BOMBERMAN_GAMEMANAGER_H
#include <curses.h>

#include "Classifica.h"

class Mappa;
class Game;

class GameManager {
    protected:
        WINDOW *win;
        Menu *menu;
        Classifica* classifica;
        Mappa* mappa;
        Game* currentGame;
        int score = 0;
        char name[13];
        bool vinto = false;

    public:

    GameManager(WINDOW *w,Menu* m);
    bool isValid(char n[]);
    void enterName();
    void startGame();
    void drawGO();
    void btnGameOver();
};


#endif //BOMBERMAN_GAMEMANAGER_H