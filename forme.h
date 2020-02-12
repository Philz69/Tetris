#ifndef FORME_H
#define FORME_H

#include <math.h>
#define MAX_SIZE 5
#define GAUCHE 0
#define DROITE 1

class Forme
{
    public:
        Forme();
        ~Forme();
        void tourner();
        void tourner(int direction);
        void setX(int x1);
        void setY(int y1);
        int getX();
        int getY();
        int getTile(int i, int j);  
    private:
        int x;
        int y;
        int matrice[MAX_SIZE][MAX_SIZE];
};

#endif
