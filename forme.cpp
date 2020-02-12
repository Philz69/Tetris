#include "forme.h"

Forme::Forme()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j != 2)
            {
                matrice[i][j] =0;
            }
            else
            {
                matrice[i][2] = 1;
            }
        }
        matrice[4][2] = 2;
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
