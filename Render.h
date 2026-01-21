#ifndef BOMBERMAN_RENDER_H
#define BOMBERMAN_RENDER_H
#include <curses.h>
#include "gioco.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"




class Render {
protected:

  WINDOW *win;
  Player *player;
  Stanza *room;
  Position maxPos;
  Bomba* bomba;



public:

  Render(WINDOW *w,Stanza *s);

  void setPlayer(Player *p);
  void setBomba(Bomba *b);
  void setStanza(Stanza *r);

  void renderPlayer();

  void renderExplosion();
  void renderBomba();

  void display();






};


#endif //BOMBERMAN_RENDER_H