#include "Globals.h"
#include <curses.h>

int maxTerminalY = 0, maxTerminalX = 0;
int startMainWinX = 0, startMainWinY = 0;

void initGlobals() {
    getmaxyx(stdscr, maxTerminalY, maxTerminalX);  // valori runtime
    startMainWinX = (maxTerminalX - X_GAME) / 2;
    startMainWinY = (maxTerminalY - Y_GAME) / 2;
}

