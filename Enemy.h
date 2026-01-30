#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H


#include "Entity.h"
#include "Stanza.h"
#include <ctime>

class Bomba;


class Enemy : public Entity {
protected:

    int vita;

    time_t lastMoveTime;
    int moveDelay = 1;

    time_t lastBombDamageTime;


public:

    Enemy(Position p, Stanza *s,int v,char c);

    void move(Bomba *b);
    void update(Bomba *b);

    int getVita();
    void setVita(int v);

    void decreaseLifeBomba(Bomba* b);

    void takeBombDamage(Bomba* bomb, int coolDown);

};


#endif //BOMBERMAN_ENEMY_H