#ifndef BOMBERMAN_BOMBA_H
#define BOMBERMAN_BOMBA_H

#include <ctime>
#include "Stanza.h"
#include "Globals.h"
#include <vector>



class Bomba {
    protected:
     char character;
     Position bombPosition;
     bool dropped = false;
     bool exploded = false;
     time_t start;
     time_t explodedTime;
     int rangeExplosion = 1;
     Stanza* room;
     int muriDistrutti = 0;
     std::vector<Position> lastBrokenMuro;


    public:

        Bomba(int y,int x,char c,Stanza* s);

        void setPosition(int y, int x);

        Position getPosition();
        char getCharacter();
        int getRangeExplosion();

        std::vector<Position> getLastBrokenMuro();
        void resetLastBrokenMuro();

        void resetBomb();

        bool isDropped();
        void setDropped(bool d);

        void explode();


        void setExploded(bool e);
        bool isExploded();

        int muriEsplosi();


        void drop(Position p);

        void update();




};

#endif //BOMBERMAN_BOMBA_H