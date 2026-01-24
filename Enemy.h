#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H


#include "Entity.h"
#include "Stanza.h"
#include <ctime>

class Bomba;


class Enemy : public Entity {
protected:

    time_t lastMoveTime;
    int moveDelay = 1;

    time_t lastBombDamageTime;


public:

    Enemy(Position p, Stanza *s);

    void move();
    void update();

    void takeBombDamage(Bomba* bomb, int coolDown);
};


#endif //BOMBERMAN_ENEMY_H