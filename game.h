#include "forme.h"
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
        bool collision(Forme *forme);
        void input();
        void descendreForme(Forme *forme);
        void nouvelleForme(Forme *forme);
        void detruireForme(Forme *forme);
        void tournerForme(Forme *forme);
        void tournerForme(Forme *forme, int direction);
        void bougerForme(Forme *forme, int x, int y);
        void changerForme();
        void formeVersBoard(Forme *forme);
        void loop();
        void afficher();
    private:
        Forme *curForme;
        int board[HAUTEUR][LARGEUR] = {0};
        std::chrono::time_point<std::chrono::high_resolution_clock> lastAction, curTime;
};
