
#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include "Globals.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomba.h"
#include "Render.h"


constexpr int MAX_NEMICI = 5;

class Game {
    protected:

        Stanza* room;
        Player* player;
        Render *render;
        Bomba* bomb;
        time_t lastDamageTime;
        int damageCooldown = 2;
        Enemy** nemici;
        int numNemici;



    public:

    Game(WINDOW* w,int numEnemies);

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