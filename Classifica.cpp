#include "Classifica.h"
#include "Globals.h"
#include <cstring>
#include "Menu.h"
#include "fstream"
using namespace std;


Classifica::Classifica(WINDOW *w,Menu* m) {
    win = w;
    menu = m;
    players = new giocatore[100];
    keypad(win, TRUE);

}

bool Classifica::isNumValid() {
    return  (numBestPlayers != -1 && numBestPlayers >= 0 && numBestPlayers <= 9999);
}


void Classifica::addPlayer(const char* name, int score) {

    for (int i = 0; i < numCurrPlayers; i++) {
        if (strcmp(players[i]->name, name) == 0) {
            if (score > players[i]->score)
                players[i]->score = score;
            return;
        }
    }

    if (numCurrPlayers < 100) {
        giocatore p = new Giocatore;
        p->name = new char[strlen(name) + 1];
        strcpy((char*)p->name, name);
        p->score = score;
        players[numCurrPlayers] = p;
        numCurrPlayers++;
    }

}

void Classifica::sortPlayers() {

    for (int i = 0; i < numCurrPlayers-1; i++)
        for (int j = i+1; j < numCurrPlayers; j++)
            if (players[i]->score < players[j]->score) {
                giocatore temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
}


void Classifica::draw() {
    box(win, 0, 0);

    const char* titolo = "CLASSIFICA";
    int nameX = (X_GAME - strlen(titolo)) / 2;
    int nameY = 1;

    wattron(win, A_BOLD);
    mvwprintw(win, nameY, nameX, "%s", titolo);
    wattroff(win, A_BOLD);

}

void Classifica::btnClassifica() {

    const char* choices[] = {"Nuova Top N" , "Menu"};
    int n_choices = sizeof(choices)/sizeof(choices[0]);

    int highlight = 0;
    int choice;

    while (true) {

        for (int i = 0; i < n_choices; i++) {
            if (i == highlight) wattron(win, A_REVERSE);
            mvwprintw(win, 20 , 7 + i * 20, "%s", choices[i]);
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
            if (strcmp(choices[highlight], "Nuova Top N") == 0)showNumInput();
            if (strcmp(choices[highlight], "Menu") == 0)menu->showMenu();


        }
    }
}

void Classifica::drawTopPlayers() {
    if (numCurrPlayers <= 0) {
        int x = 10;
        int y = 7;
        wattron(win, A_UNDERLINE);
        mvwprintw(win, y, x, "La classifica e' vuota!");
        wattroff(win, A_UNDERLINE);

    }else {
        if (numBestPlayers > numCurrPlayers) numBestPlayers = numCurrPlayers;
        int x = 2;
        int y = 4;

        wattron(win, A_UNDERLINE);
        mvwprintw(win, y, x, "Pos  Giocatore               Punteggio");
        wattroff(win, A_UNDERLINE);

        for (int i = 0; i < numBestPlayers; i++)
            mvwprintw(win, y + i + 1, x , "%3d  %-12s            %6d" ,i+1,players[i]->name,players[i]->score);
    }

}

void Classifica::showClassifica() {

    werase(win);
    draw();
    sortPlayers();
    drawTopPlayers();
    btnClassifica();
    wrefresh(win);

}



void Classifica::showNumInput() {
    int y = 10;
    const char* titolo = "Inserisci N:";
    int nameL = strlen(titolo);
    int x = ((X_GAME - nameL) / 2) - 7;

    bool valid = false;

    while (!valid) {
        werase(win);
        draw();
        mvwprintw(win, y, x, "%s", titolo);
        wmove(win, y, x + nameL + 1);
        wrefresh(win);

        noecho();
        int ch;
        numBestPlayers = 0;
        bool hasInput = false;

        while ((ch = wgetch(win)) != '\n') {
            if (numBestPlayers <= 9999 && ch >= '0' && ch <= '9') {
                numBestPlayers = numBestPlayers * 10 + (ch - '0');
                waddch(win, ch);
                wrefresh(win);
                hasInput = true;
            }
            if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
                if (numBestPlayers > 0) {
                    numBestPlayers /= 10;
                    int cx, cy;
                    getyx(win, cy, cx);
                    mvwaddch(win, cy, cx - 1, ' ');
                    wmove(win, cy, cx - 1);
                    wrefresh(win);
                }
                if (numBestPlayers == 0) hasInput = false;
            }
        }

        echo();

        if (hasInput && isNumValid()) {
            valid = true;
        } else {
            mvwprintw(win, y + 2, x - 2, "Numero non valido, riprova!");
            wrefresh(win);
            napms(1000);
        }
    }
    showClassifica();
}


void Classifica::saveALLPlayersToFile() {

    ofstream file("classifica.txt", ios::trunc);
    if (!file.is_open()) return;

    for (int i = 0; i < numCurrPlayers; i++) {
        file << players[i]->name << " " << players[i]->score << "\n";
    }

    file.close();
}


void Classifica::loadClassifica() {
    ifstream file("classifica.txt");
    if (!file.is_open()) return;

    char name[13];
    int score;

    for (int i = 0; i < numCurrPlayers; i++) {
        delete[] players[i]->name;
        delete players[i];
    }
    numCurrPlayers = 0;

    while (file >> name >> score) {
        giocatore p = new Giocatore;
        p->name = new char[strlen(name) + 1];
        strcpy((char*)p->name, name);
        p->score = score;
        players[numCurrPlayers] = p;
        numCurrPlayers++;
    }

    file.close();
}






