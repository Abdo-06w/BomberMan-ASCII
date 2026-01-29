#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <curses.h>
#include "Globals.h"
#include "Bomba.h"
#include "Stanza.h"
#include "Entity.h"


struct PlayerStats {
    int rangeMultiplier;
    int damageMultiplier;
    int vita;
};


class Player : public Entity {
 protected:

    Bomba* bomba;
    time_t lastEnemyDamageTime;
    time_t lastBombDamageTime;

    PlayerStats stats;

    bool damaged = false;


 public:

    Player(Position p ,Bomba* b,Stanza* s);

    void setStanza(Stanza *s);

    int getVita();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void handleInput(int input);

    void droppaBomba();

    void decreaseLifeBomba();

    void takeBombDamage(int coolDown);

    void decreaseLifeEnemy();

    void takeEnemyDamage(Position enemyPos,int coolDown);

    int getRangeMultiplier();
    int getDamageMultiplier();

    void setRangeMultiplier(int r);
    void setDamageMultiplier(int d);

    bool takenDamage();


    PlayerStats getStats();

    void setStats(int v,int d,int r);








};




#endif //BOMBERMAN_PLAYER_H