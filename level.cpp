#include "level.h"

Level::Level()
{
    tickTime = 800;
    pointMultiplier = 1;
    levelNumber = 0;
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

int Level::getPointMultiplier()
{
    return pointMultiplier;
}