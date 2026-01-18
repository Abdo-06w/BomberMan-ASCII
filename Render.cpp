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
    mvwaddch(win,o.y,o.x,' ');

    Position p = player->getPosition();
    mvwaddch(win,p.y,p.x,player->getCharacter());

}


void Render::renderBomba() {
    if (bomba->isDropped())
        mvwaddch(win, bomba->getPosition().y, bomba->getPosition().x, '*');
    else if (bomba->isExploded())
        mvwaddch(win, bomba->getPosition().y, bomba->getPosition().x, 'X');
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

};