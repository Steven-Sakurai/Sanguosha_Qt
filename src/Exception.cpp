#include "Lib.h"

GameOverException::GameOverException(GameResult r)
{
    result=r;
}

GameOverException::~GameOverException()
{
}

DisturbedException::DisturbedException(int i)
{
    index=i;
}

DisturbedException::~DisturbedException()
{
}
