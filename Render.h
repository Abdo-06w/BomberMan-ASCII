#ifndef BOMBERMAN_RENDER_H
#define BOMBERMAN_RENDER_H
#include <curses.h>
#include "Globals.h"
#include "Player.h"
#include "Stanza.h"
#include "Bomba.h"
#include "Enemy.h"




class Render {
protected:

  WINDOW *win;
  Player *player;
  Stanza *room;
  Position maxPos;
  Bomba* bomba;
  Enemy* enemies[];



public:

  Render(WINDOW *w,Stanza *s);

  void setPlayer(Player *p);
  void setBomba(Bomba *b);
  void setStanza(Stanza *r);
  void setEnemies(Enemy* e[],int numNemici);

  void renderPlayer();
  void renderEnemy(Enemy* e);

  void renderExplosion();
  void renderBomba();

  void display();






};


#endif //BOMBERMAN_RENDER_H