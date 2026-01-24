#include "Bomba.h"
#include "Stanza.h"
#include "Player.h"
#include <ctime>

Bomba::Bomba(int y,int x,char c,Stanza* s) {
    bombPosition.y = y;
    bombPosition.x = x;
    character = c;
    room = s;
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
int Bomba::getRangeExplosion() {
    return rangeExplosion;
}
bool Bomba::isDropped() {
    return dropped;
}
void Bomba::setDropped(bool d) {
    dropped = d;
}
void Bomba::setExploded(bool e) {
    exploded = e;
}
bool Bomba::isExploded() {
    return exploded;
}

int Bomba::getDamage() {
    return damage;
}

void Bomba::setStats(int r, int d) {
    rangeExplosion = r;
    damage = d;
}

int Bomba::getBaseDamage() {
    return baseDamage;
}
int Bomba::getBaseRange() {
    return baseRange;
}


void Bomba::resetBomb() {
    exploded = false;
    bombPosition.y = -1;
    bombPosition.x = -1;
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

        explode();
        exploded = true;
        explodedTime = now;
        dropped = false;
    }
    if (exploded && difftime(now, explodedTime) > 1)
        resetBomb();

}


void Bomba::explode() {

    Position b = bombPosition;
    int newY,newX;

    if (room->isMuro(b.y, b.x)) {
        room->breakWall(b.y, b.x);
    }

    for (int i = 0; i < 4; i++) {

        for (int j = 1; j <= rangeExplosion; j++) {

            newY = b.y + directions[i].y * j ;
            newX = b.x + directions[i].x * j ;

            if (newY < 0 || newY >= room->getStanzaY() || newX < 0 || newX >= room->getStanzaX() || room->isMuroInd(newY, newX))
                break;

            if (room->isMuro(newY,newX)) {
                room->breakWall(newY,newX);
                muriDistrutti++;
                if (numBrokenMuro < MAX_BROKEN_WALLS) {
                    lastBrokenMuro[numBrokenMuro++] = { newY, newX };
                }
            }
        }
    }
}
int Bomba::muriEsplosi() {
    int tmp = muriDistrutti;
    muriDistrutti = 0;
    return tmp;
}

int Bomba::getNumBrokenMuro() {
    return numBrokenMuro;
}

Position Bomba::getBrokenMuro(int i) {
    return lastBrokenMuro[i];
}
void Bomba::resetLastBrokenMuro() {
    numBrokenMuro = 0;
}






