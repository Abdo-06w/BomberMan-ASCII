#include "Time.h"

int Time::getTime() {
    return time;
}
void Time::setTime(int n) {
    if (n < 0)n=0;
    time = n;
}
void Time::addTime(int n) {
    time += n;
}