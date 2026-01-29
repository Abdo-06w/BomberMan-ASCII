#include "Game.h"
#include <cstdlib>



Game::Game(WINDOW *win,Stanza* r,Points* p) {
    room = r;
    bomb = new Bomba(-1,-1,'*',room);
    player = new Player({1,1},bomb,room);
    render = new Render(win,room);

    points = p;

    numNemici = 0;
    nemici = new Enemy*[MAX_NEMICI];

    render->setBomba(bomb);
    render->setPlayer(player);
    render->setStanza(room);
    render->setPoints(points);

    items = new Item*[MAX_ITEMS];
    numItems = 0;


}

Player* Game::getPlayer() { return player; }
Bomba* Game::getBomba() { return bomb; }
Stanza* Game::getRoom() { return room; }
Enemy** Game::getEnemies() { return nemici; }
Render* Game::getRender() { return render; }
Points* Game::getPoints() { return points; }


int Game::getNumNemici() { return numNemici; }

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
        points->addPoints(10*muri);

    int dead = nemiciMorti();
    if (dead > 0)
        points->addPoints(100*dead);
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

void Game::dropItem(Position p) {

    int chance = rand() % 100;

    if (numItems < MAX_ITEMS && player->getDamageMultiplier() < 4 && chance < 30) {
        items[numItems] = new Item('D');
        items[numItems]->setPosition(p);
        numItems++;
    }

    if (numItems < MAX_ITEMS && player->getRangeMultiplier() < 3 && chance > 70) {
        items[numItems] = new Item('R');
        items[numItems]->setPosition(p);
        numItems++;
    }

}

void Game::getItem() {
    Position p = player->getPosition();

    for (int i = 0; i < numItems; i++) {

        if (p.x == items[i]->getPosition().x && p.y == items[i]->getPosition().y) {
            items[i]->setEffect(player);
            items[i]->collect();
            delete items[i];
            items[i] = items[numItems - 1];
            numItems--;
            i--;
        }
        else if ((items[i]->getCharacter() == 'D' && player->getDamageMultiplier() >= 4) ||
                 (items[i]->getCharacter() == 'R' && player->getRangeMultiplier() >= 3)) {

            items[i]->collect();
            delete items[i];
            items[i] = items[numItems - 1];
            numItems--;
            i--;
        }
    }
}

void Game::resetUpgrade() {
    player->setRangeMultiplier(1);
    player->setDamageMultiplier(1);
}

void Game::update() {

     for (int i = 0; i < numNemici; i++)
            nemici[i]->update();

        bomb->update();

        for (int i = 0; i < numNemici; i++)
         player->takeEnemyDamage(nemici[i]->getPosition(), damageCooldown);

        bombDamage();

        addPoints();

        for (int i = 0; i < bomb->getNumBrokenMuro(); i++) {
            Position wall = bomb->getBrokenMuro(i);
            dropItem(wall);
        }

        bomb->resetLastBrokenMuro();

        getItem();

        checkEnemyLife();

        if (player->takenDamage())
            resetUpgrade();
}

void Game::renderGame() {

    render->display();

    for (int i = 0; i < numItems; i++)
        render->renderItems(items[i]);

    for (int i = 0; i < numNemici; i++)
        render->renderEnemy(nemici[i]);

    render->renderPlayer();

    render->renderBomba();
}


Game::~Game() {

    for (int i = 0; i < numItems; i++) {
        delete nemici[i];
        nemici[i] = NULL;
    }

    delete player;
    player = NULL;

    delete bomb;
    bomb = NULL;

    delete render;
    render = NULL;

    for (int i = 0; i < numItems; i++) {
        delete items[i];
        items[i] = NULL;
    }

}



