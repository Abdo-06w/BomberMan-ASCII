#include "Game.h"


Game::Game(WINDOW *win) {

    room = new Stanza(win,20,40);
    bomb = new Bomba(-1,-1,'*',room);
    player = new Player({0,0},bomb,room);
    render = new Render(win,room);

    nemici[0] = new Enemy{{17,3},room};
    nemici[1] = new Enemy{{6,6},room};
    nemici[2] = new Enemy{{10,30},room};

    render->setBomba(bomb);
    render->setPlayer(player);
    render->setStanza(room);


}

Player* Game::getPlayer() { return player; }
Bomba* Game::getBomba() { return bomb; }
Stanza* Game::getRoom() { return room; }
Enemy** Game::getEnemies() { return nemici; }
Render* Game::getRender() { return render; }



void Game::damage() {

    time_t now = time(NULL);

    Position p = player->getPosition();

    if (difftime(now, lastDamageTime) < damageCooldown)
        return;


        for (int i = 0; i < numNemici; i++) {
            Position n = nemici[i]->getPosition();

            if (n.y == p.y && n.x == p.x) {
                player->decreaseLife();
                lastDamageTime = now;
                return;
            }
        }
}

void Game::update() {

     for (int i = 0; i < numNemici; i++) {
            nemici[i]->update();
        }

        bomb->update();

}

void Game::renderGame() {
    render->display();

    for (int i = 0; i < numNemici; i++) {
        render->renderEnemy(nemici[i]);
    }
}


