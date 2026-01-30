#include "Points.h"

void Points::addPoints(int p) {
    points += p;
}

int Points::getPoints() {
    return points;
}

void Points::resetPoints() {
    points = 0;
}