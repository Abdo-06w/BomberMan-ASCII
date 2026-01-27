#include "Globals.h"
#include "Enemy.h"
#include "Stanza.h"
#include "Bomba.h"
#include <cstdlib>

Enemy::Enemy(Position p, Stanza *s) {

    playerPosition = p;
    stanza = s;
    character = 'O';
    vita = 2;

}

void Enemy::move() {

    Position p = getPosition();

        int dir = rand() % 4;

        int newY = p.y + directions[dir].y;
        int newX = p.x + directions[dir].x;

        if (newY < 0 || newY >= stanza->getStanzaY() ||
            newX < 0 || newX >= stanza->getStanzaX())
            return;

        if (stanza->isMuro(newY, newX) || stanza->isMuroInd(newY, newX)
            || stanza->isPortaNext(newY,newX) || stanza->isPortaPrev(newY,newX))
            return;

        setPosition(newY, newX);

}

void Enemy::update() {

    time_t now = time(NULL);

    if (difftime(now, lastMoveTime) >= moveDelay) {

        /*move();*/

        lastMoveTime = now;
    }

}

int Enemy::getVita() {
    return vita;
}


void Enemy::setVita(int v) {
    vita = v;
}

void Enemy::decreaseLifeBomba(Bomba* b) {
    vita = vita - b->getDamage();
}

void Enemy::takeBombDamage(Bomba* bomb, int damageCooldown) {
    if (!bomb->isExploded()) return;

    time_t now = time(NULL);
    if (difftime(now, lastBombDamageTime) < damageCooldown)
        return;

    Position b = bomb->getPosition();
    int r = bomb->getRangeExplosion();
    Position p = getPosition();

    if (b.y == p.y && b.x == p.x) {
        decreaseLifeBomba(bomb);
        lastBombDamageTime = now;
        return;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= r; j++) {
            int newY = b.y + directions[i].y * j;
            int newX = b.x + directions[i].x * j;
            if (newY == p.y && newX == p.x) {
                decreaseLifeBomba(bomb);
                lastBombDamageTime = now;
                return;
            }
        }
    }
}


