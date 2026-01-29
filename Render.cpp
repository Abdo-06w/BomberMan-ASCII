#include "Render.h"
#include <curses.h>
#include "Globals.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"
#include "Game.h"


Render::Render(WINDOW *w,Stanza *s) {

    win = w;
    room = s;
    keypad(win, true);
    getmaxyx(win, maxPos.y, maxPos.x);

}

void Render::setPlayer(Player *p) {
    player = p;
}
void Render::setBomba(Bomba *b) {
    bomba = b;
}
void Render::setStanza(Stanza *r) {
    room = r;
}
void Render::setPoints(Points *p) {
    points = p;
}


void Render::renderPlayer() {

    Position p = player->getPosition();
    wattron(win, COLOR_PAIR(7));
    mvwaddch(win,p.y + 1,p.x + 1,player->getCharacter());
    wattroff(win, COLOR_PAIR(7));
}

void Render::renderEnemy(Enemy* e) {
    if (!e) return;

    Position p = e->getPosition();
    wattron(win, COLOR_PAIR(5));
    mvwaddch(win, p.y + 1, p.x + 1, e->getCharacter());
    wattroff(win, COLOR_PAIR(5));

}

void Render::renderExplosion() {
    if (!bomba->isExploded()) return;

    Position b = bomba->getPosition();


    wattron(win, COLOR_PAIR(4));
    mvwaddch(win, b.y + 1, b.x + 1, ' ');
    wattroff(win, COLOR_PAIR(4));


    for (int i = 0; i < 4; i++) {
        bool stopDirection = false;
        for (int j = 1; j <= bomba->getRangeExplosion() && !stopDirection; j++) {
            int newY = b.y + directions[i].y * j;
            int newX = b.x + directions[i].x * j;

            if (newY < 0 || newY >= room->getStanzaY() || newX < 0 || newX >= room->getStanzaX()
                || room->isMuroInd(newY, newX) || room->isPortaNext(newY,newX) || room->isPortaPrev(newY,newX)) {
                stopDirection = true;
                continue;
            }

            wattron(win, COLOR_PAIR(4));
            mvwaddch(win, newY + 1, newX + 1, ' ');
            wattroff(win, COLOR_PAIR(4));
        }
    }
}

void Render::renderBomba() {
    if (bomba->isDropped() ){
        wattron(win, COLOR_PAIR(9));
        mvwaddch(win, bomba->getPosition().y + 1, bomba->getPosition().x + 1, '*');
        wattroff(win, COLOR_PAIR(9));

    }

    else if (bomba->isExploded())
        renderExplosion();

}

void Render::renderItems(Item* item) {

        if (!item->isCollected()) {
            Position p = item->getPosition();
            wattron(win, COLOR_PAIR(6));
            mvwaddch(win, p.y + 1, p.x + 1, item->getCharacter());
            wattroff(win, COLOR_PAIR(6));
        }
}



void Render::renderTime(Mappa *m) {

    int t = m->getTimer()->getTime();


    if (t > 0)
        mvwprintw(win,0,2, "Tempo: %d", t);
    else
        mvwprintw(win,0,2, "Tempo: %d", 0);

}


void Render::display() {

    box(win, 0, 0);
    mvwprintw(win,0,15, "Vita: %d", player->getVita());
    mvwprintw(win,0,25, "Punti: %d", points->getPoints());
    mvwprintw(win,maxPos.y-1, 10, "Range: x%d", player->getRangeMultiplier());
    mvwprintw(win,maxPos.y-1, 20, "Damage: x%d", player->getDamageMultiplier());



    for (int i = 0; i < room->getStanzaY(); i++) {
        for (int j = 0; j < room->getStanzaX(); j++) {


            if (room->isMuroInd(i, j)) {
                wattron(win, COLOR_PAIR(2));
                mvwaddch(win, i+1, j+1, ' ');
                wattroff(win, COLOR_PAIR(2));
            }
            else if (room->isMuro(i, j)) {
                wattron(win, COLOR_PAIR(3));
                mvwaddch(win, i+1, j+1, ' ');
                wattroff(win, COLOR_PAIR(3));
            }
            else if (room->isPortaNext(i,j) || room->isPortaPrev(i,j)){
                wattron(win, COLOR_PAIR(10));
                mvwaddch(win, i+1, j+1, ' ');
                wattroff(win, COLOR_PAIR(10));

            }
            else {
                wattron(win, COLOR_PAIR(1));
                mvwaddch(win, i+1, j+1, ' ');
                wattroff(win, COLOR_PAIR(1));
            }

        }
    }

}