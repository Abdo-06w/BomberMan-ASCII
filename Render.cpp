#include "Render.h"
#include <curses.h>
#include "gioco.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"


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


void Render::renderPlayer() {

    Position o = player->getOldPosition();
    mvwaddch(win,o.y + 1,o.x + 1,' ');

    Position p = player->getPosition();
    mvwaddch(win,p.y + 1,p.x + 1,player->getCharacter());

}

void Render::renderExplosion() {
    if (!bomba->isExploded()) return;

    Position b = bomba->getPosition();


        mvwaddch(win, b.y + 1, b.x + 1, 'X');


    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= bomba->getRangeExplosion(); j++) {
            int newY = b.y + directions[i].y * j;
            int newX = b.x + directions[i].x * j;

            if (newY < 0 || newY >= room->getStanzaY() || newX < 0 || newX >= room->getStanzaX())
                continue;

            mvwaddch(win, newY + 1, newX + 1, 'X');
        }
    }
}



void Render::renderBomba() {
    if (bomba->isDropped())
        mvwaddch(win, bomba->getPosition().y + 1, bomba->getPosition().x + 1, '*');
    else if (bomba->isExploded())
        renderExplosion();

}

void Render::display() {

    box(win, 0, 0);
    for (int i = 0; i < room->getStanzaY(); i++) {
        for (int j = 0; j < room->getStanzaX(); j++) {
            mvwaddch(win, i + 1, j + 1, room->isMuro(i, j) ? '#' : '.');
        }
    }

    renderPlayer();
    renderBomba();

}