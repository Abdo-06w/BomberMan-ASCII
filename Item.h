#ifndef BOMBERMAN_ITEM_H
#define BOMBERMAN_ITEM_H
#include "Position.h"


class Item {
    protected:
        char character;
        Position position;
    public:

        Item(char c);

        void setPosition(Position p);
        Position getPosition();
        char getCharacter();

};


#endif //BOMBERMAN_ITEM_H