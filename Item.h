#ifndef BOMBERMAN_ITEM_H
#define BOMBERMAN_ITEM_H
#include "Position.h"
#include "Player.h"

class Mappa;

class Item {
    protected:
        char character;
        Position position;
        bool collected = false;
    public:

        Item(char c);

        bool isCollected();
        void collect();

        void setPosition(Position p);
        Position getPosition();
        char getCharacter();

        void setEffect(Player *p,Mappa* m);

};


#endif //BOMBERMAN_ITEM_H