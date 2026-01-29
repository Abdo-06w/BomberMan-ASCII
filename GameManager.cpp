#include "GameManager.h"
#include <cstring>
#include "Globals.h"
#include "Classifica.h"
#include "Mappa.h"
#include "Game.h"

GameManager::GameManager(WINDOW *w,Menu *m) {
    win = w;
    menu = m;
    classifica = m->getClassifica();

    keypad(win, true);

}

bool GameManager::isValid(char n[]) {

    size_t len = strlen(n);
    if (len < 2 || len > 12) return false;

    return true;

}


void GameManager::enterName() {

    int y = 7;
    const char* titolo = "Inserisci il tuo nome:";
    int nameL = strlen(titolo);
    int x = ((X_GAME - nameL) / 2) - 1;

    bool valid = false;



    while (!valid) {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, y, x, "%s", titolo);
        wmove(win, y, x + nameL + 1);
        wrefresh(win);

        noecho();

        int inputY = y + 3;
        int inputX = x+4;

        wmove(win, inputY, inputX);
        wrefresh(win);


        int ch;
        int pos = 0;
        char tmpnome[13];
        tmpnome[0] = '\0';

        while ((ch = wgetch(win)) != '\n') {
            if (pos < 12 && ch >= 32 && ch <= 126) {
                tmpnome[pos++] = ch;
                tmpnome[pos] = '\0';
                waddch(win, ch);
                wrefresh(win);
            }
            else if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
                if (pos > 0) {
                    pos--;
                    tmpnome[pos] = '\0';
                    mvwaddch(win, inputY, inputX + pos, ' ');
                    wmove(win, inputY, inputX + pos);
                    wrefresh(win);
                }
            }else{}

        }

        echo();

        if (isValid(tmpnome)) {
            valid = true;
            strcpy(name,tmpnome);
        } else {
            mvwprintw(win, y + 6, x-1, "Nome non valido, riprova!");
            wrefresh(win);
            napms(1000);
        }
    }

   startGame();
}



void GameManager::btnGameOver() {
    const char* choices[] = {"Nuova Partita" , "Menu"};
    int n_choices = sizeof(choices)/sizeof(choices[0]);

    int highlight = 0;
    int choice;

    while (true) {
        for (int i = 0; i < n_choices; i++) {
            if (i == highlight) wattron(win, A_REVERSE);
            mvwprintw(win, 18 , 7 + i * 20, "%s", choices[i]);
            if (i == highlight) wattroff(win, A_REVERSE);
        }
        wrefresh(win);

        choice = wgetch(win);

        switch (choice) {
            case KEY_LEFT:
                highlight--;
                if (highlight < 0) highlight = n_choices-1;
                break;
            case KEY_RIGHT:
                highlight++;
                if (highlight >= n_choices) highlight = 0;
                break;
            default:
                break;
        }

        if (choice == 10 || choice == KEY_ENTER) {
            if (strcmp(choices[highlight], "Nuova Partita") == 0) {
                delete mappa;
                mappa = NULL;
                name[0] = '\0';
                enterName();
                return;
            }
            if (strcmp(choices[highlight], "Menu") == 0) {
                delete mappa;
                mappa = NULL;
                name[0] = '\0';
                menu->showMenu();
                return;
            }
        }
    }
}




void GameManager::drawGO() {
    werase(win);
    box(win, 0, 0);

    const char* title = "GAME OVER";
    wattron(win, A_BOLD | A_UNDERLINE);
    mvwprintw(win, 3, ( X_GAME - strlen(title)) / 2 - 1, "%s", title);
    wattroff(win, A_BOLD | A_UNDERLINE);

    mvwprintw(win, 7, ( X_GAME - strlen(name)) / 2 - 1, "%s", name);

    const char* result = vinto ? "YOU WIN!" : "YOU LOSE!";
    wattron(win, A_BOLD);
    mvwprintw(win, 10, (X_GAME - strlen(result)) / 2 - 1, "%s", result);
    wattroff(win, A_BOLD);

    wrefresh(win);
}







void GameManager::startGame() {

    mappa = new Mappa(win);
    currentGame = mappa->getCurrentGame();


    currentGame->getRender()->display();
    currentGame->getRender()->renderTime(mappa);

    nodelay(win, TRUE);
    noecho();

    do{


        mappa->update();
        currentGame = mappa->getCurrentGame();

        int input = wgetch(win);
        if (input != ERR) {
            currentGame->getPlayer()->handleInput(input);
        }

        currentGame->update();

        werase(win);
        currentGame->renderGame();
        currentGame->getRender()->renderTime(mappa);
        wrefresh(win);


    }while (!mappa->endGame());

    vinto = mappa->getHasWon();

    if (vinto) {
        int s = mappa->score()->getPoints();
        classifica->addPlayer(name,s);
        classifica->saveALLPlayersToFile();
    }
    drawGO();
    nodelay(win, FALSE);
    btnGameOver();

}






