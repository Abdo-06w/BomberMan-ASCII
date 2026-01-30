#include "Entity.h"
#include "Bomba.h"

void Entity::setPosition(int y, int x) {
    playerPosition.y = y;
    playerPosition.x = x;
}

Position Entity::getPosition() {
    return playerPosition;
}

char Entity::getCharacter() {
    return character;
}

