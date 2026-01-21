#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H
#include "Entity.h"
#include "Stanza.h"

#include <ctime>


class Enemy : public Entity {
protected:

    time_t lastMoveTime;
    int moveDelay = 1;


public:

    Enemy(Position p, Stanza *s);

    void move();
    void update();

};


#endif //BOMBERMAN_ENEMY_H