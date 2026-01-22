#include "Game.h"


Game::Game(WINDOW *win) {


    room = new Stanza(win,20,40);
    bomb = new Bomba(-2,-2,'*',room);
    player = new Player({0,0},bomb,room);
    render = new Render(win,room);

    numNemici = 0;
    nemici = new Enemy*[MAX_NEMICI];

    render->setBomba(bomb);
    render->setPlayer(player);
    render->setStanza(room);


}

Player* Game::getPlayer() { return player; }
Bomba* Game::getBomba() { return bomb; }
Stanza* Game::getRoom() { return room; }
Enemy** Game::getEnemies() { return nemici; }
Render* Game::getRender() { return render; }

int Game::getNumNemici() {
    return numNemici;
}

void Game::addEnemy(Position p) {
    if (numNemici >= MAX_NEMICI)
        return;

    nemici[numNemici] = new Enemy(p, room);
    numNemici++;

}


void Game::checkEnemyLife() {
    if (numNemici <= 0)return;

    for (int i = 0; i < numNemici; i++) {

        if (nemici[i]->getVita() <= 0) {

            delete nemici[i];

            nemici[i] = nemici[numNemici-1];
            numNemici--;
            i--;
        }
    }
}

void Game::bombDamage() {
    for (int i = 0; i < numNemici; i++)
        nemici[i]->takeBombDamage(bomb, damageCooldown);

    player->takeBombDamage(damageCooldown);
}




void Game::update() {

     for (int i = 0; i < numNemici; i++) {
            nemici[i]->update();
        }

        bomb->update();

        for (int i = 0; i < numNemici; i++)
        player->takeEnemyDamage(nemici[i]->getPosition(), damageCooldown);

        bombDamage();

        checkEnemyLife();



}

void Game::renderGame() {
    render->display();

    for (int i = 0; i < numNemici; i++) {
        render->renderEnemy(nemici[i]);
    }
}


