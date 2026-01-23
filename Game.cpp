#include "Game.h"
#include <cstdlib>




Game::Game(WINDOW *win) {


    room = new Stanza(win,20,40);
    bomb = new Bomba(-2,-2,'*',room);
    player = new Player({0,0},bomb,room);
    points = new Points();
    render = new Render(win,room);


    numNemici = 0;
    nemici = new Enemy*[MAX_NEMICI];

    render->setBomba(bomb);
    render->setPlayer(player);
    render->setStanza(room);
    render->setPoints(points);


}

Player* Game::getPlayer() { return player; }
Bomba* Game::getBomba() { return bomb; }
Stanza* Game::getRoom() { return room; }
Enemy** Game::getEnemies() { return nemici; }
Render* Game::getRender() { return render; }
Points* Game::getPoints() { return points; }

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
            deadEnemies++;

        }
    }
}

void Game::bombDamage() {
    for (int i = 0; i < numNemici; i++)
        nemici[i]->takeBombDamage(bomb, damageCooldown);

    player->takeBombDamage(damageCooldown);
}

int Game::nemiciMorti() {
    int tmp = deadEnemies;
    deadEnemies = 0;
    return tmp;
}

void Game::addPoints() {
        int muri = bomb->muriEsplosi();
        if (muri > 0)
            points->addPoints(100*muri);

        int dead = nemiciMorti();
        if (dead > 0)
            points->addPoints(1000*dead);
}

void Game::dropItem(Position p) {

    int chance = rand() % 100;

    if (chance < 30){
        Item* i = new Item('o');
        i->setPosition(p);
        items.push_back(i);
        render->addItem(i);
    }

}

void Game::update() {

     for (int i = 0; i < numNemici; i++) {
            nemici[i]->update();
        }

        bomb->update();

        for (int i = 0; i < numNemici; i++)
        player->takeEnemyDamage(nemici[i]->getPosition(), damageCooldown);

        bombDamage();

        addPoints();

        std::vector<Position> walls = bomb->getLastBrokenMuro();

        for (Position wall : bomb->getLastBrokenMuro())
            dropItem(wall);

        bomb->resetLastBrokenMuro();


        checkEnemyLife();



}

void Game::renderGame() {


    render->display();


    for (int i = 0; i < numNemici; i++) {
        render->renderEnemy(nemici[i]);
    }


}


