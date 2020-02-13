#include "game.h"

using namespace std;

Game :: Game()
{
    curForme = new Forme(rand() % FORMEZ);
    curForme->setX(4);
    curForme->setY(2);
}
Game ::~Game()
{
    detruireForme(curForme);
}

void Game :: afficher()
{
    int offsetX;
    int offsetY;
    for(int i = 0; i < HAUTEUR; i++)
    {
        cout << '|';
        for(int j = 0; j < LARGEUR; j++)
        {
            offsetX = curForme->getX() - j + 2;
            offsetY = curForme->getY() - i + 2;
            if(board[i][j] == 1 || curForme->getTile(offsetX, offsetY) == 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "|" << '\n';
    }
    cout << flush;
   
}

bool Game :: collision(Forme *forme)
{
    int xforme = forme->getX();
    int yforme = forme->getY();
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            if( ( board[yforme + (i -2)][xforme +(j -2)] == 1 && forme->getTile(i,j) == 1 ) || yforme + (i -2) > 23)
            {
                return true;
            }
        }
    }

    return false;
}
void Game :: input()
{
    if(kbhit())
    {
    int pressedChar;
    pressedChar = getch();
    if(pressedChar == 77)
    {
        tournerForme(curForme);
        afficher();
    }
    }
}
void Game :: descendreForme(Forme *forme)
{
        forme->setY(forme->getY() - 1);
        if(collision(forme) == true)
        {
            forme->setY(forme->getY() + 1);
            formeVersBoard(forme);
            detruireForme(forme);
            nouvelleForme(forme);
        }
}
void Game :: tournerForme(Forme *forme)
{
    curForme->tourner();
}
void Game :: nouvelleForme(Forme *forme)
{
    forme = new Forme(rand() % FORMEZ);
    forme->setX(5);
    forme->setY(2);
}
void Game :: detruireForme(Forme *forme)
{
  delete forme;

}

void Game :: formeVersBoard(Forme *forme)
{
    cout << "TEST" << endl;
    cout << forme->getX() << endl;
      cout << "TEST2" << endl;
    int xforme = forme->getX();
  
    int yforme = forme->getY();
     for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            board[yforme + (i -2)][xforme +(j -2)] = forme->getTile(i,j);
        }
    }
}

void Game :: loop()
{
    while(true)
    {
    input();
    /*if(lastAction - curTime > 500)
    {
        descendreForme(curForme);
    }*/

    }

    
}
