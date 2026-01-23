#ifndef BOMBERMAN_POINTS_H
#define BOMBERMAN_POINTS_H


class Points {
    protected:

    int points = 0;

    public:

    void addPoints(int p);

    int  getPoints();

    void resetPoints();


};


#endif //BOMBERMAN_POINTS_H