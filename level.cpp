#include "level.h"

Level::Level()
{
    tickTime = 800;
    levelNumber = 0;
}

void Level::update(int linesCleared)
{
    if(linesCleared / 10 > levelNumber)
    {
        next();
    }
}

void Level::next()
{
    levelNumber += 1;
    tickTime = 1000*(48.0 - (5.0*levelNumber)) / 60.0;
}

int Level::getLevelNumber()
{
    return levelNumber;
}

int Level::getTickTime()
{
    return tickTime;
}


int Level::getScore(int lines)
{
	if(lines == 1)
	{
		return 40*(levelNumber + 1);
	}
	else if(lines == 2)
	{
		return 100*(levelNumber + 1);
	}
	else if(lines == 3)
	{
		return 300*(levelNumber + 1);
	}
	else if(lines > 3)
	{
		return 300*lines*(levelNumber + 1);
	}
    else
    {
        return 0;
    }
}