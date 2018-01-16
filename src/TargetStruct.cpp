#include "Lib.h"
#include "TargetStruct.h"

TargetStruct::TargetStruct(Player *p) : valid(true)
{
    player=p;tag=NULL;
}

string TargetStruct::toString()
{
    return player->toString();//TODO: cards like 借刀杀人
}
