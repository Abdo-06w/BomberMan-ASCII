#include "Globals.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"
#include "Entity.h"


Player::Player(Position p, Bomba* b, Stanza* s) {
    playerPosition = p;
    bomba = b;
    stanza = s;
    character = '@';
    vita = 3;

}

void Player::droppaBomba() {
    if (bomba->isDropped() || bomba->isExploded())
        return;

    bomba->drop(playerPosition);

}



void Player::moveDown() {

    int newY = playerPosition.y + 1;
    int roomY = stanza->getStanzaY();
    if (newY > roomY - 1) newY = roomY - 1;
    if (stanza->isMuro(newY , playerPosition.x) || stanza->isMuroInd(newY , playerPosition.x)) newY--;
    playerPosition.y = newY;
}

void Player::moveUp() {

    int newY = playerPosition.y - 1;
    if (newY < 0) newY = 0;
    if (stanza->isMuro(newY , playerPosition.x) || stanza->isMuroInd(newY , playerPosition.x)) newY++;
    playerPosition.y = newY;
}

void Player::moveLeft() {

    int newX = playerPosition.x - 1;
    if (newX < 0) newX = 0;
    if (stanza->isMuro(playerPosition.y , newX) || stanza->isMuroInd(playerPosition.y , newX)) newX++;
    playerPosition.x = newX;
}

void Player::moveRight() {
    int newX = playerPosition.x + 1;
    int roomX = stanza->getStanzaX();
    if (newX > roomX - 1) newX = roomX - 1;
    if (stanza->isMuro(playerPosition.y , newX) || stanza->isMuroInd(playerPosition.y , newX)) newX--;
    playerPosition.x = newX;
}

void Player::handleInput(int input) {
    switch(input) {
        case KEY_UP:    moveUp(); break;
        case KEY_DOWN:  moveDown(); break;
        case KEY_LEFT:  moveLeft(); break;
        case KEY_RIGHT: moveRight(); break;
        case 32:        droppaBomba(); break;
            default: break;
    }
}

void Player::takeBombDamage(int coolDown) {

    if (!bomba->isExploded())return;

    time_t now = time(NULL);

    if (difftime(now, lastBombDamageTime) < coolDown)
        return;

    Position p = getPosition();
    Position b = bomba->getPosition();
    int r = bomba->getRangeExplosion();



    if (b.y == p.y && b.x == p.x) {
        decreaseLife();
        lastBombDamageTime = now;
        return;
    }

    int newY,newX;

    for (int i = 0; i < 4; i++) {

        for (int j = 1; j <= r; j++) {

            newY = b.y + directions[i].y * j ;
            newX = b.x + directions[i].x * j ;

            if (newY == p.y && newX == p.x) {
                decreaseLife();
                lastBombDamageTime = now;
                return;
            }
        }
    }

}

void Player::takeEnemyDamage(Position enemyPos,int coolDown) {

    time_t now = time(NULL);
    if (difftime(now, lastEnemyDamageTime) < coolDown)
        return;

    Position p = getPosition();
    if (p.x == enemyPos.x && p.y == enemyPos.y) {
        decreaseLife();
        lastEnemyDamageTime = now;
    }

}





