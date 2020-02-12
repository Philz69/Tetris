#include "forme.h"

Forme::Forme(int type)
{
    if(type == FORMEI)
    {
       //int matrice[MAX_SIZE][MAX_SIZE] = 
       //{{0,0,0,0,0},
       //{0,0,1,0,0},
       //{0,0,1,0,0},
       //{0,0,1,0,0},
       //{0,0,1,0,0}};
        matrice[1][2] = 1;
        matrice[2][2] = 1;
        matrice[3][2] = 1;
        matrice[4][2] = 1;
    }
    if(type == FORMEJ)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,1,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};

    }
    if(type == FORMEL)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,0,0,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};

    }
    if(type == FORMEO)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,1,1,0},
        {0,0,0,0,0}};
        
    }
    if(type == FORMES)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,1,1,0,0},
        {0,0,0,0,0}};
        
    }
    if(type == FORMET)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};
    }
    if(type == FORMEZ)
    {
        int matrice[MAX_SIZE][MAX_SIZE] = 
        {{0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,1,0,0},
        {0,0,1,1,0},
        {0,0,0,0,0}};
    }
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
