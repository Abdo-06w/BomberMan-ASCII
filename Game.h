
#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include "Globals.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomba.h"
#include "Render.h"


class Game {
    protected:

        Stanza* room;
        Player* player;
        Render *render;
        Enemy* nemici[numNemici];
        Bomba* bomb;
        time_t lastDamageTime;
        int damageCooldown = 2;



    public:

    Game(WINDOW* w);

    Player* getPlayer();
    Bomba* getBomba();
    Stanza* getRoom();
    Enemy** getEnemies();
    Render* getRender();

    void update();

    void damage();

    void renderGame();



};


#endif //BOMBERMAN_GAME_H