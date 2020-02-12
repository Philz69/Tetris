#include "test.h"
using namespace std;

void Test::testFormes()
{
	Forme I(FORMEI);
	afficherForme(I);
	I.tourner();
	afficherForme(I);
	I.tourner();
	afficherForme(I);
	I.tourner();
	afficherForme(I);
}

void Test::afficherForme(Forme forme)
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
	for(int j = 0; j < MAX_SIZE; j++)
	{
		cout << forme.getTile(i,j);
	}
	cout << endl;
	}
}
