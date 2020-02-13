#include "forme.h"
#include <chrono>
#include <stdlib.h>
#include <iostream>
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
        void tournerForme(Forme *forme);
        void nouvelleForme(Forme *forme);
        void detruireForme(Forme *forme);
        void formeVersBoard(Forme *forme);
        void loop();
        void afficher();
    private:
        Forme *curForme;
        int board[HAUTEUR][LARGEUR] = {0};
        double lastAction, curTime;
};
