#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <curses.h>
#include "gioco.h"
#include "Bomba.h"
#include "Stanza.h"


class Player {
 protected:

    Position playerPosition;
    Position oldPosition;
    char character;
    Bomba* bomba;
    Stanza* stanza;
    Position maxPos;



 public:

    Player(Position p, char c,Bomba* b,Stanza* s);

    void setPosition(int y, int x);

    Position getPosition();
    Position getOldPosition();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void handleInput(int input);

    void droppaBomba();

    char getCharacter();




};




#endif //BOMBERMAN_PLAYER_H