#include "Bomba.h"
#include "Stanza.h"
#include "Player.h"
#include <ctime>

Bomba::Bomba(int y,int x,char c) {
    bombPosition.y = y;
    bombPosition.x = x;
    character = c;
}


void Bomba::setPosition(int y, int x) {
    bombPosition.y = y;
    bombPosition.x = x;
}

Position Bomba::getPosition() {
    return bombPosition;
}


char Bomba::getCharacter() {

    return character;
}

bool Bomba::isDropped() {
    return dropped;
}

void Bomba::setDropped(bool d) {
    dropped = d;
}


void Bomba::drop(Position p) {

    bombPosition = p;
    dropped = true;
    exploded = false;
    start = time(NULL);
}


void Bomba::update() {

    time_t now = time(NULL);

    if (dropped && difftime(now, start) > 2) {
        dropped = false;
        explode();
        exploded = true;
        explodedTime = now;
    }

    if (exploded && difftime(now, explodedTime) > 1) {
        exploded = false;
        bombPosition.y = -1;
        bombPosition.x = -1;
    }
}

void Bomba::setExploded(bool e) {
    exploded = e;
}


bool Bomba::isExploded() {
    return exploded;
}


void Bomba::explode() {

}

