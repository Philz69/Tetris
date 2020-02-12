#include <math.h>
#define MAX_SIZE 5

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
  
    private:
    int x;
    int y;
    int matrice[MAX_SIZE][MAX_SIZE];
}

Forme::Forme()
{
    for(int i = 0; i < 5; i++)
    {
        matrice[i][2] = 1;
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

void Forme:: tourner()
{
    int tmp[MAX_SIZE][MAX_SIZE];
    
    for(int i=0;i< MAX_SIZE;i++)
    {
        for(int j=0;j< MAX_SIZE;j++)
        {
             tmp[i][MAX_SIZE - j] = matrice[i][j];
        }
    }
}

void Forme:: tourner(int direction)
{
    int tmp[MAX_SIZE][MAX_SIZE];
    
    for(int i=0;i< MAX_SIZE;i++)
    {
        for(int j=0;j< MAX_SIZE;j++)
        {
             tmp[MAX_SIZE - i][MAX_SIZE - j] = matrice[i][j];
        }
    }
}



