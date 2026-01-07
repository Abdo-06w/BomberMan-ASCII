#include <iostream>
#include <curses.h>
#include "Menu.h"

using namespace std;


int main() {

    initscr();
    noecho();
    cbreak();

    mostraMenu();


    getch();
    endwin();

    return 0;
}


// g++ *.cpp -o bomber -lpdcurses