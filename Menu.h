#ifndef BOMBERMAN_MENU_H
#define BOMBERMAN_MENU_H


class GameManager;
class Classifica;



class Menu {
    protected:

     WINDOW* win;
     Classifica* classifica;
     GameManager* gameManager;


    public:

    Menu(WINDOW* w);

    Classifica* getClassifica();
    GameManager* getGameManager();

    void drawMenu();

    void showMenu();



};
#endif