#include "Item.h"


Item::Item(char c) {
    character = c;
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
