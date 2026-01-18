#ifndef BOMBERMAN_BOMBA_H
#define BOMBERMAN_BOMBA_H

#include <ctime>

#include "gioco.h"



class Bomba {
    protected:
     char character;
     Position bombPosition;
     bool dropped = false;
     bool exploded = false;
    time_t start;
    time_t explodedTime;


    public:

        Bomba(int y,int x,char c);

        void setPosition(int y, int x);
        Position getPosition();
        char getCharacter();

        bool isDropped();
        void setDropped(bool d);

        void explode();


        void setExploded(bool e);
        bool isExploded();

        void drop(Position p);

        void update();










};

#endif //BOMBERMAN_BOMBA_H