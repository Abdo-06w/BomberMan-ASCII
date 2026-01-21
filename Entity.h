#ifndef BOMBERMAN_CHARACTER_H
#define BOMBERMAN_CHARACTER_H

#include "Position.h"
#include "Stanza.h"


class Entity {
    protected:
    Position playerPosition;
    char character;
    Stanza* stanza;
    int vita;

    public:

    void setPosition(int y, int x);
    void setVita(int v);

    Position getPosition();
    char getCharacter();
    int getVita();

    void decreaseLife();







};


#endif //BOMBERMAN_CHARACTER_H