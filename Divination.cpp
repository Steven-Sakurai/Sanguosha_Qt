#include "Lib.h"
#include "Divination.h"

bool Divination::legalityCheck(Player *target, PreUseStruct *d)
{
    return true;
}

Divination::Divination() : NonEquipCard("无中生有",Trick)
{
}

void Divination::resolve(TargetStruct *target, UseStruct *d)
{
    target->player->draw(2);
}

bool Divination::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return target==d->player;
}
