#include "Globals.h"
#include "Enemy.h"
#include "Stanza.h"
#include "Bomba.h"
#include <cstdlib>
#include <algorithm>

Enemy::Enemy(Position p, Stanza *s,int v,char c) {
    playerPosition = p;
    stanza = s;
    character = c;
    vita = v;
}

void Enemy::move(Bomba *b) {
    Position bomba = b->getPosition() ;
    Position p = getPosition();

    int tried[4] = {0, 1, 2, 3};

    for (int i = 3; i > 0; i--) {
        int j = rand() % (i+1);
        std::swap(tried[i], tried[j]);
    }

    for (int k = 0; k < 4; k++) {
        int dir = tried[k];
        int newY = p.y + directions[dir].y;
        int newX = p.x + directions[dir].x;

        if (newY < 0 || newY >= stanza->getStanzaY() ||
            newX < 0 || newX >= stanza->getStanzaX())
            continue;

        if (bomba.x == newX && bomba.y == newY)
            continue;

        if (stanza->isMuro(newY, newX) || stanza->isMuroInd(newY, newX)
            || stanza->isPortaNext(newY,newX) || stanza->isPortaPrev(newY,newX))
            continue;

        setPosition(newY, newX);
        return;
    }
}

void Enemy::update(Bomba *b) {
    time_t now = time(NULL);

    if (difftime(now, lastMoveTime) >= moveDelay) {
        move(b);
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
        bool stopDirection = false;
        for (int j = 1; j <= r && !stopDirection; j++) {

            int newY = b.y + directions[i].y * j;
            int newX = b.x + directions[i].x * j;

            if (newY < 0 || newY >= stanza->getStanzaY() || newX < 0 || newX >= stanza->getStanzaX()
               || stanza->isMuroInd(newY, newX) || stanza->isPortaNext(newY,newX) || stanza->isPortaPrev(newY,newX)) {
                stopDirection = true;
                break;
               }

            if (newY == p.y && newX == p.x) {
                decreaseLifeBomba(bomb);
                lastBombDamageTime = now;
                return;
            }
        }
    }
}


