#include "Lib.h"
#include "EquipCard.h"
#include "UseEvent.h"

bool EquipCard::legalityCheck(Player *target, PreUseStruct *d)
{
    return false;
}

EquipCard::EquipCard(string n, EquipType et):CardType(n,Equip)
{
    maxTargets=0;equipType=et;
}

bool EquipCard::use(PreUseStruct *d)
{
    vector<MoveStruct*> testData;
    for(int i=0;i<d->cards.size();i++) testData.push_back(new MoveStruct(d->cards[i],&d->player->equipArea));
    d->testMove=new PrimitiveMoveEvent(testData);
    d->testMove->happen();
    if(!d->isLegal())
    {
        d->player->inform("error:illegal_use");
        d->testMove->undo();
        delete d;
        return false;
    }
    d->testMove->undo();
    vector<Player*> targets;
    UseStruct *data=new UseStruct(d,targets);
    (new UseEvent(data))->happen();
    return true;
}
