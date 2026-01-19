#include "gioco.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"


Player::Player(Position p, char c,Bomba* b, Stanza* s) {

    playerPosition = p;
    bomba = b;
    character = c;
    stanza = s;

}


void Player::setPosition(int y, int x) {
    playerPosition.y = y;
    playerPosition.x = x;
}

Position Player::getPosition() {
    return playerPosition;
}
Position Player::getOldPosition() {
    return oldPosition;
}
char Player::getCharacter() {
    return character;
}


void Player::droppaBomba() {
    if (bomba->isDropped() || bomba->isExploded())
        return;

    bomba->drop(playerPosition);

}



void Player::moveDown() {
    oldPosition = playerPosition;
    int newY = playerPosition.y + 1;
    int roomY = stanza->getStanzaY();
    if (newY > roomY - 1) newY = roomY - 1;
    if (stanza->isMuro(newY , playerPosition.x ) == 1) newY--;
    playerPosition.y = newY;
}

void Player::moveUp() {
    oldPosition = playerPosition;
    int newY = playerPosition.y - 1;
    if (newY < 0) newY = 0;
    if (stanza->isMuro(newY , playerPosition.x ) == 1) newY++;
    playerPosition.y = newY;
}

void Player::moveLeft() {
    oldPosition = playerPosition;
    int newX = playerPosition.x - 1;
    if (newX < 0) newX = 0;
    if (stanza->isMuro(playerPosition.y , newX ) == 1) newX++;
    playerPosition.x = newX;
}

void Player::moveRight() {
    oldPosition = playerPosition;
    int newX = playerPosition.x + 1;
    int roomX = stanza->getStanzaX();
    if (newX > roomX - 1) newX = roomX - 1;
    if (stanza->isMuro(playerPosition.y , newX ) == 1) newX--;
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



