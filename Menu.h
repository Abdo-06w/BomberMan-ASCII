#ifndef BOMBERMAN_MENU_H
#define BOMBERMAN_MENU_H


class Classifica;



class Menu {
    protected:

     WINDOW* win;
     Classifica* classifica;


    public:

    Menu(WINDOW* w);

    void drawMenu();

    void showMenu();



};
#endif