#include "Time.h"

int Time::getTime() {
    return time;
}
void Time::setTime(int n) {
    time = n;
}
void Time::addTime(int n) {
    time += n;
}
