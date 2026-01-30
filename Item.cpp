#include "Item.h"
#include <algorithm>

#include "Mappa.h"
#include "Time.h"


#include <iostream>

Item::Item(char c) {
    character = c;
    collected = false;

}

bool Item::isCollected() {
    return collected;
}
void Item::collect() {
    collected = true;
}

Position Item::getPosition() {
    return position;
}
void Item::setPosition(Position p) {
    position = p;
}
char Item::getCharacter() {
    return character;
}

void Item::setEffect(Player *p,Mappa* m) {

    if (character == 'D') {
        int newMultiplier = p->getDamageMultiplier() + 1;
        p->setDamageMultiplier(std::min(newMultiplier, 2));
    }
    else if (character == 'R') {
        int newMultiplier = p->getRangeMultiplier() + 1;
        p->setRangeMultiplier(std::min(newMultiplier, 3));
    }
    else if (character == 'T') {
        m->getTimer()->addTime(15);
    }


}

