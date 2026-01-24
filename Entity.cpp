#include "Entity.h"
#include "Bomba.h"

void Entity::setPosition(int y, int x) {
    playerPosition.y = y;
    playerPosition.x = x;
}
void Entity::setVita(int v) {
    vita = v;
}

Position Entity::getPosition() {
    return playerPosition;
}

char Entity::getCharacter() {
    return character;
}
int Entity::getVita() {
    return vita;
}
void Entity::decreaseLifeBomba(Bomba* b) {
    vita = vita - b->getDamage();
}