
#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include "Globals.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomba.h"
#include "Render.h"
#include "Points.h"
#include "Item.h"
#include "Time.h"


constexpr int MAX_NEMICI = 6;
constexpr int MAX_ITEMS = 10;
#include <chrono>
using namespace std::chrono;

class Game {
    protected:

        Stanza* room;
        Player* player;
        Render *render;
        Bomba* bomb;

        Points* points;

        Item** items;
        int numItems;

        int damageCooldown = 2;
        Enemy** nemici;
        int numNemici;

        int deadEnemies = 0;



    public:

    Game(WINDOW* w,Stanza* r,Points* p);
    ~Game();


    Player* getPlayer();
    Bomba* getBomba();
    Stanza* getRoom();
    Render* getRender();
    Enemy** getEnemies();
    Points* getPoints();
    int getNumNemici();

    void update(Mappa* m);

    void bombDamage();

    void checkEnemyLife();

    void addEnemy(Position p,int v,char c);

    void addPoints();

    void renderGame();

    int nemiciMorti();

    void dropItem(Position p);

    void getItem(Mappa* m);

    void resetUpgrade();



};


#endif //BOMBERMAN_GAME_H