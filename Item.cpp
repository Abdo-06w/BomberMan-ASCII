#include "Item.h"
#include <algorithm>

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

void Item::setEffect(Player *p) {

    if (character == 'D') {
        int newMultiplier = p->getDamageMultiplier() + 1;
        p->setDamageMultiplier(std::min(newMultiplier, 4));
    }
    else if (character == 'R') {
        int newMultiplier = p->getRangeMultiplier() + 1;
        p->setRangeMultiplier(std::min(newMultiplier, 3));
    }


}

