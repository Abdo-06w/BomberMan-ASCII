#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <curses.h>
#include "Globals.h"
#include "Bomba.h"
#include "Stanza.h"
#include "Entity.h"


class Player : public Entity {
 protected:

    Bomba* bomba;
    time_t lastEnemyDamageTime;
    time_t lastBombDamageTime;

    int rangeMultiplier = 1;
    int damageMultiplier = 1;

    bool damaged = false;


 public:

    Player(Position p ,Bomba* b,Stanza* s);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void handleInput(int input);

    void droppaBomba();

    void takeBombDamage(int coolDown);

    void decreaseLifeEnemy();

    void takeEnemyDamage(Position enemyPos,int coolDown);

    int getRangeMultiplier();
    int getDamageMultiplier();

    void setRangeMultiplier(int r);
    void setDamageMultiplier(int d);

    bool takenDamage();








};




#endif //BOMBERMAN_PLAYER_H