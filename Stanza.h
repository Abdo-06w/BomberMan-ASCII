
#ifndef BOMBERMAN_STANZA_H
#define BOMBERMAN_STANZA_H

#include <curses.h>

class Stanza {
    protected:
        int roomY;
        int roomX;
        int** terreno;
        WINDOW* currWindow;



    public:

        Stanza(WINDOW *win,int y,int x);

        void stampaStanza();

        bool isMuro(int y,int x);

        bool isMuroInd(int y,int x);

        int getStanzaY();

        int getStanzaX();

        void breakWall(int y, int x);



};


#endif //BOMBERMAN_STANZA_H