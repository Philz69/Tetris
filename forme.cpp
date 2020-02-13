#include "forme.h"
using namespace std;

Forme::Forme(int type)
{
    if(type == FORMEI)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,1,0,0};
       matrice[2] = new int[MAX_SIZE] {0,0,1,0,0};
       matrice[3] = new int[MAX_SIZE] {0,0,1,0,0};
       matrice[4] = new int[MAX_SIZE] {0,0,1,0,0};
    }
    if(type == FORMEJ)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,1,0,0,0};
       matrice[2] = new int[MAX_SIZE] {0,1,1,1,0};
       matrice[3] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
    if(type == FORMEL)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,0,1,0};
       matrice[2] = new int[MAX_SIZE] {0,1,1,1,0};
       matrice[3] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
    if(type == FORMEO)
    {
       
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[2] = new int[MAX_SIZE] {0,0,1,1,0};
       matrice[3] = new int[MAX_SIZE] {0,0,1,1,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
    if(type == FORMES)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[2] = new int[MAX_SIZE] {0,0,1,1,0};
       matrice[3] = new int[MAX_SIZE] {0,1,1,0,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
    if(type == FORMET)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,1,0,0};
       matrice[2] = new int[MAX_SIZE] {0,1,1,1,0};
       matrice[3] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
    if(type == FORMEZ)
    {
       matrice = new int*[MAX_SIZE];
       matrice[0] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[1] = new int[MAX_SIZE] {0,0,0,0,0};
       matrice[2] = new int[MAX_SIZE] {0,1,1,0,0};
       matrice[3] = new int[MAX_SIZE] {0,0,1,1,0};
       matrice[4] = new int[MAX_SIZE] {0,0,0,0,0};
    }
}

Forme::~Forme()
{
    delete [] matrice;
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
                cout << "TEST" << endl;
    int **tmp = new int*[MAX_SIZE];

                cout << "TEST" << endl;
    for(int i=0;i< MAX_SIZE;i++)
    {
                cout << "TEST" << endl;
        tmp[i] = new int[MAX_SIZE];
                cout << "TEST" << endl;
        for(int j=0;j< MAX_SIZE;j++)
        {
            if(direction == GAUCHE)
            {
                cout << "BEFORE DELETE" << endl;
            tmp[i][j] = matrice[j][i];
            }
            else
            {
                cout << "BEFORE DELETE" << endl;
            tmp[i][j] = matrice[MAX_SIZE - 1 - j][i];
            }
        }
    }


                cout << "BEFORE DELETE" << endl;
    delete matrice;
    matrice = tmp;
}


int Forme::getTile(int i, int j)
{
    if(i > MAX_SIZE || j > MAX_SIZE)
    {
        return -1;
    }
    return matrice[i][j];
}
#
