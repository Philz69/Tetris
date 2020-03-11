#include "forme.h"
#include "level.h"
#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#define LARGEUR 10
#define HAUTEUR 24  

class Game
{
    public:
        Game();
        ~Game();
        void afficher();
        bool collision(Forme *forme);
        void ligneComplete();
        void shiftBoard(int index);
        void input();
        void mort();
        void bougerForme(Forme *forme, int x, int y);
        void changerForme();
        void tournerForme(Forme *forme);
        void tournerForme(Forme *forme, int direction);
        void formeVersBoard(Forme *forme);
        void loop();
    private:
        Forme *curForme;
        Forme *preview;
        Forme *prochaineForme;
        Level level;
        int board[HAUTEUR][LARGEUR] = {0};
        int score;
        int linesCleared;
        bool alive; 
        std::chrono::time_point<std::chrono::high_resolution_clock> lastAction, curTime;
};
