#ifndef BOMBERMAN_CHARACTER_H
#define BOMBERMAN_CHARACTER_H

#include "Position.h"
#include "Stanza.h"
#include <ctime>

class Bomba;


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

    void decreaseLifeBomba(Bomba *b);







};


#endif //BOMBERMAN_CHARACTER_H