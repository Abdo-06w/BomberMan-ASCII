#include "gioco.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"



/*Player::Player(WINDOW *win,int y,int x,char c,Stanza *s,Bomba* b) {

    currWindow = win;
    position.y = y;
    position.x = x;
    character = c;
    stanza = s;
    bomba = b;
    keypad(currWindow, true);
    getmaxyx(currWindow, maxPos.y, maxPos.x);

}*/

Player::Player(WINDOW *win,Position p, char c,Bomba* b, Stanza* s) {

    playerPosition = p;
    bomba = b;
    character = c;
    stanza = s;
    currWindow = win;
    getmaxyx(win, maxPos.y, maxPos.x);

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

void Player::droppaBomba() {
    if (bomba->isDropped())
        return;

    bomba->drop(playerPosition);

}

char Player::getCharacter() {
    return character;
}



void Player::moveDown() {
    oldPosition = playerPosition;
    int newY = playerPosition.y + 1;
    if (newY > maxPos.y - 2) newY = maxPos.y - 2;
    if (stanza->isMuro(newY - 1, playerPosition.x - 1) == 1) newY--;
    playerPosition.y = newY;
}

void Player::moveUp() {
    oldPosition = playerPosition;
    int newY = playerPosition.y - 1;
    if (newY < 1) newY = 1;
    if (stanza->isMuro(newY - 1, playerPosition.x - 1) == 1) newY++;
    playerPosition.y = newY;
}

void Player::moveLeft() {
    oldPosition = playerPosition;
    int newX = playerPosition.x - 1;
    if (newX < 1) newX = 1;
    if (stanza->isMuro(playerPosition.y - 1, newX - 1) == 1) newX++;
    playerPosition.x = newX;
}

void Player::moveRight() {
    oldPosition = playerPosition;
    int newX = playerPosition.x + 1;
    if (newX > maxPos.x - 2) newX = maxPos.x - 2;
    if (stanza->isMuro(playerPosition.y - 1, newX - 1) == 1) newX--;
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

/*int Player::getMovement() {

    int choice = wgetch(currWindow);

    switch (choice) {
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;
        case KEY_RIGHT:
            moveRight();
            break;
        case 32:
            droppaBomba();
        default:
            break;
    }

    return choice;

}*/

/*void Player::display() {

    PositionBomba b = bomba->getPosition();

    mvwaddch(currWindow, b.y, b.x,bomba->getCharacter());
    mvwaddch(currWindow, playerPosition.y, position.x, character);

    bomba->update();


};*/



