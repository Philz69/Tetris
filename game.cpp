#include "game.h"

#define FLECHE_GAUCHE 75
#define FLECHE_DROITE 77
#define FLECHE_HAUT 72
#define FLECHE_BAS 80

using namespace std;

Game ::Game()
{
    curForme = new Forme(rand() % FORMEZ);
    curForme->setX(4);
    curForme->setY(2);
    lastAction = std::chrono::high_resolution_clock::now();
}
Game ::~Game()
{
    delete curForme;
}

void Game ::afficher()
{
    int offsetX;
    int offsetY;
    cout << "______" << '\n';
    for (int i = 0; i < HAUTEUR; i++)
    {
        cout << setw(2) << i << setw(1) << '|';
        for (int j = 0; j < LARGEUR; j++)
        {
            offsetX = -(curForme->getX() - j - 2);
            offsetY = -(curForme->getY() - i - 2);
            if (board[i][j] == 1 || curForme->getTile(offsetY, offsetX) == 1)
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
    cout << "______" << '\n';
    cout << flush;
}

bool Game::collision(Forme *forme)
{
    int xCentreForme = forme->getX();
    int yCentreForme = forme->getY();
    int xGlobal;
    int yGlobal;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            xGlobal = xCentreForme + (j - 2);
            yGlobal = yCentreForme + (i - 2);
            if (forme->getTile(i, j) == 1 && (board[yGlobal][xGlobal] == 1 || yGlobal > 23 || xGlobal < 0 || xGlobal > 9))
            {
                cout << "xGlobal: " << xGlobal << endl;
                return true;
            }
        }
    }

    return false;
}

void Game::ligneComplete()
{
    int lignePleine = 1;
    for (int i = 0; i < HAUTEUR; i++)
    {
        lignePleine = 1;
        for (int j = 0; j < LARGEUR; j++)
        {
           if(board[i][j] != 1)
           {
              lignePleine = 0;
           }
        }
        if(lignePleine == 1)
        {
            shiftBoard(i);
            i--;
        }
    }

}

void Game::shiftBoard(int index)
{
    for(int i = index; i > 0; i--)
    {
        for(int j = 0; j < LARGEUR; j++)
        {
            board[i][j] = board[i-1][j];
        }
    }
}
void Game ::input()
{
    if (kbhit())
    {
        int pressedChar;
        pressedChar = getch();
        switch (pressedChar)
        {
        case FLECHE_HAUT:
            tournerForme(curForme);
            afficher();
            break;
        case FLECHE_DROITE:
            bougerForme(curForme, 1, 0);
            afficher();
            break;
        case FLECHE_GAUCHE:
            bougerForme(curForme, -1, 0);
            afficher();
            break;
        case FLECHE_BAS:
            bougerForme(curForme, 0, 23);
            afficher();
            break;
        }
    }
}
void Game::bougerForme(Forme *forme, int x, int y)
{
    int xInitial = forme->getX();
    int yInitial = forme->getY();
    if (x > 0)
    {

        for (int i = 0; i <= x; i++)
        {
            forme->setX(xInitial + i);
            cout << "xInitial + i: " << xInitial << "+" << i << "=" << xInitial + i << endl;
            if (collision(forme) == true)
            {
                forme->setX(xInitial + i - 1);
                break;
            }
        }
    }
    else if (x < 0)
    {
        for (int i = 0; i >= x; i--)
        {
            forme->setX(xInitial + i);
            cout << "xInitial + i: " << xInitial << "+" << i << "=" << xInitial + i << endl;
            if (collision(forme) == true)
            {
                forme->setX(xInitial + i + 1);
                break;
            }
        }
    }
    for (int i = 0; i <= y; i++)
    {
        forme->setY(yInitial + i);
        if (collision(forme) == true)
        {
            forme->setY(yInitial + i - 1);
            formeVersBoard(forme);
            changerForme();
            break;
        }
    }

}

void Game ::changerForme()
{
    Forme *tmp = new Forme(rand() % FORMEZ);
    tmp->setX(5);
    tmp->setY(2);
    delete curForme;
    curForme = tmp;
}

void Game ::tournerForme(Forme *forme)
{
    tournerForme(forme, DROITE);
}

void Game ::tournerForme(Forme *forme, int direction)
{
    forme->tourner(direction);
    if(collision(forme) == true)
    {
        forme->tourner(direction * -1);
    }
}

void Game ::formeVersBoard(Forme *forme)
{
    int xforme = forme->getX();
    int yforme = forme->getY();
    cout << "Center coords: " << yforme << "," << xforme << endl;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            cout << forme->getTile(i, j);
            if (forme->getTile(i, j) == 1)
            {
                board[yforme + (i - 2)][xforme + (j - 2)] = forme->getTile(i, j);
            }
        }
        cout << endl;
    }
}

void Game::loop()
{
    afficher();
    while (true)
    {
        input();
        if (std::chrono::high_resolution_clock::now() - lastAction > std::chrono::milliseconds{500})
        {
            bougerForme(curForme, 0, 1);
            afficher();
            ligneComplete();
            afficher();
            lastAction = std::chrono::high_resolution_clock::now();
        }
    }
}


