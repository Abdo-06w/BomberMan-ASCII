
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
#include <vector>


constexpr int MAX_NEMICI = 5;

class Game {
    protected:

        Stanza* room;
        Player* player;
        Render *render;
        Bomba* bomb;
        Points* points;
        std::vector<Item*> items;


        int damageCooldown = 2;
        Enemy** nemici;
        int numNemici;

        int deadEnemies = 0;



    public:

    Game(WINDOW* w);

    Player* getPlayer();
    Bomba* getBomba();
    Stanza* getRoom();
    Render* getRender();
    Enemy** getEnemies();
    Points* getPoints();
    int getNumNemici();


    void update();

    void bombDamage();

    void checkEnemyLife();

    void addEnemy(Position p);

    void addPoints();

    void renderGame();

    int nemiciMorti();

    void dropItem(Position p);



};


#endif //BOMBERMAN_GAME_H