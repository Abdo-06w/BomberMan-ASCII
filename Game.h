
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


        int damageCooldown = 2;
        Enemy** nemici;
        int numNemici;



    public:

    Game(WINDOW* w);

    Player* getPlayer();
    Bomba* getBomba();
    Stanza* getRoom();
    Render* getRender();
    Enemy** getEnemies();
    int getNumNemici();

    void update();

    void enemyDamage();
    void bombDamagePlayer();

    void damagePlayer();
    void bombDamage();

    void checkEnemyLife();

    void addEnemy(Position p);

    void renderGame();



};


#endif //BOMBERMAN_GAME_H