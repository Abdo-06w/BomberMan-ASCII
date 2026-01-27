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


    public:

    void setPosition(int y, int x);


    Position getPosition();
    char getCharacter();

    /*void setVita(int v);


    int getVita();

    void decreaseLifeBomba(Bomba *b);*/







};


#endif //BOMBERMAN_CHARACTER_H