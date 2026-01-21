#ifndef BOMBERMAN_CHARACTER_H
#define BOMBERMAN_CHARACTER_H

#include "gioco.h"
#include "Stanza.h"


class Entity {
    protected:
    Position playerPosition;
    Position oldPosition;
    char character;
    Stanza* stanza;

    public:

    void setPosition(int y, int x);

    Position getPosition();
    Position getOldPosition();
    char getCharacter();





};


#endif //BOMBERMAN_CHARACTER_H