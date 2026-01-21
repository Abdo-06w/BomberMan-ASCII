#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <curses.h>
#include "gioco.h"
#include "Bomba.h"
#include "Stanza.h"
#include "Entity.h"


class Player : public Entity {
 protected:

    Bomba* bomba;

 public:

    Player(Position p ,Bomba* b,Stanza* s);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void handleInput(int input);

    void droppaBomba();






};




#endif //BOMBERMAN_PLAYER_H