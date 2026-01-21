#include "Entity.h"



void Entity::setPosition(int y, int x) {
    playerPosition.y = y;
    playerPosition.x = x;
}

Position Entity::getPosition() {
    return playerPosition;
}
Position Entity::getOldPosition() {
    return oldPosition;
}
char Entity::getCharacter() {
    return character;
}