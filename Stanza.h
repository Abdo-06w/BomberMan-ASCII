
#ifndef BOMBERMAN_STANZA_H
#define BOMBERMAN_STANZA_H

#include <curses.h>

#include "Position.h"

class Stanza {
    protected:
        int roomY;
        int roomX;
        int** terreno;
        WINDOW* currWindow;



    public:

        Stanza(WINDOW *win,int y,int x,int m[20][40]);

        bool isMuro(int y,int x);

        bool isMuroInd(int y,int x);

        int getStanzaY();

        int getStanzaX();

        void breakWall(int y, int x);

        bool isPortaNext(int y,int x);
        bool isPortaPrev(int y,int x);

        void delPortaPrev();
        void delPortaNext();

        bool isTherePortaNext();
        bool isTherePortaPrev();


};


#endif //BOMBERMAN_STANZA_H