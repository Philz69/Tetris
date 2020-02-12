#include "forme.h"

Forme::Forme(int type)
{
    if(type = FORMEI)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,1,0,0};
        matrice[2][] = {0,0,1,0,0};
        matrice[3][] = {0,0,1,0,0};
        matrice[4][] = {0,0,1,0,0};

    }
    if(type = FORMEJ)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,1,0,0,0};
        matrice[2][] = {0,1,1,1,0};
        matrice[3][] = {0,0,0,0,0};
        matrice[4][] = {0,0,0,0,0};

    }
    if(type = FORMEL)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,0,1,0};
        matrice[2][] = {0,1,1,1,0};
        matrice[3][] = {0,0,0,0,0};
        matrice[4][] = {0,0,0,0,0};

    }
    if(type = FORMEO)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,0,0,0};
        matrice[2][] = {0,0,1,1,0};
        matrice[3][] = {0,0,1,1,0};
        matrice[4][] = {0,0,0,0,0};
        
    }
    if(type = FORMES)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,0,0,0};
        matrice[2][] = {0,0,1,1,0};
        matrice[3][] = {0,1,1,0,0};
        matrice[4][] = {0,0,0,0,0};
        
    }
    if(type = FORMET)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,1,0,0};
        matrice[2][] = {0,1,1,1,0};
        matrice[3][] = {0,0,0,0,0};
        matrice[4][] = {0,0,0,0,0};
    }
    if(type = FORMEZ)
    {
        matrice[0][] = {0,0,0,0,0};
        matrice[1][] = {0,0,0,0,0};
        matrice[2][] = {0,1,1,0,0};
        matrice[3][] = {0,0,1,1,0};
        matrice[4][] = {0,0,0,0,0};
    }
}
Forme::~Forme()
{
}
int Forme::getX()
{
    return x;
} 
int Forme::getY()
{
    return y;
} 
void Forme::setX(int x1)
{
    x= x1;
} 
void Forme::setY(int y1)
{
    y= y1;
} 

void Forme::tourner()
{
    tourner(DROITE);
}

void Forme:: tourner(int direction)
{
    int tmp[MAX_SIZE][MAX_SIZE];

    for(int i=0;i< MAX_SIZE;i++)
    {
        for(int j=0;j< MAX_SIZE;j++)
        {
            if(direction == GAUCHE)
            {
            tmp[i][j] = matrice[j][i];
            }
            else
            {
            tmp[i][j] = matrice[MAX_SIZE - 1 - j][i];
            }
        }
    }

    for(int i=0;i< MAX_SIZE;i++)
    {
        for(int j=0;j< MAX_SIZE;j++)
        {
            matrice[i][j] =            tmp[i][j] ;
        }
    }

}


int Forme::getTile(int i, int j)
{
    return matrice[i][j];
}
#
