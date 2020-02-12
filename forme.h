#ifndef FORME_H
#define FORME_H

#include <math.h>
#define MAX_SIZE 5
#define GAUCHE 0
#define DROITE 1
#define FORMEI 0
#define FORMEJ 1
#define FORMEL 2
#define FORMEO 3
#define FORMES 4
#define FORMET 5
#define FORMEZ 6


 
class Forme
{
    public:
        Forme(int type);
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
        int matrice[MAX_SIZE][MAX_SIZE] = {0};
};


#endif