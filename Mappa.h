#ifndef BOMBERMAN_MAPPA_H
#define BOMBERMAN_MAPPA_H
#include "Stanza.h"
#include "Player.h"
#include <chrono>

#include "Points.h"
using namespace std::chrono;

class Game;

struct Maps {
    Stanza* livello;
    Game* game;
    Maps* prev;
    Maps* next;

};
typedef Maps *pMap;



class Time;


class Mappa {
    protected:

    WINDOW *win;
    Points* points;

    pMap map1;
    pMap map2;
    pMap map3;
    pMap map4;
    pMap map5;

    pMap current;

    Time* time;
    steady_clock::time_point lastTick;


    public:

    Mappa(WINDOW *win);

    Stanza* getCurrentRoom();
    Game* getCurrentGame();

    Time* getTimer();

    void nextRoom();
    void prevRoom();

    void update(Player* p);

    void timer();





};


#endif //BOMBERMAN_MAPPA_H