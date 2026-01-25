#ifndef BOMBERMAN_BOMBA_H
#define BOMBERMAN_BOMBA_H

#include <ctime>
#include "Stanza.h"
#include "Globals.h"

constexpr int MAX_BROKEN_WALLS = 100;




class Bomba {
    protected:
     char character;
     Position bombPosition;
     bool dropped = false;
     bool exploded = false;
     time_t start;
     time_t explodedTime;
     Stanza* room;
     int muriDistrutti = 0;

    Position lastBrokenMuro[MAX_BROKEN_WALLS];
    int numBrokenMuro = 0;

    int baseRange = 1;
    int baseDamage = 1;
    int rangeExplosion = 1;
    int damage = 1;


    public:

        Bomba(int y,int x,char c,Stanza* s);

        void setPosition(int y, int x);

        Position getPosition();
        char getCharacter();
        int getRangeExplosion();
        void resetLastBrokenMuro();

        int getNumBrokenMuro();
        Position getBrokenMuro(int i);

        void resetBomb();

        int getDamage();
        void setStats(int r, int d);
        int getBaseRange();
        int getBaseDamage();

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