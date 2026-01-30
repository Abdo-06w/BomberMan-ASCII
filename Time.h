#ifndef BOMBERMAN_TIME_H
#define BOMBERMAN_TIME_H


class Time {
    protected:
        int time = 200;

    public:

        int getTime();
        void setTime(int n);
        void addTime(int n);




};


#endif //BOMBERMAN_TIME_H