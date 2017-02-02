#include "Lib.h"
#include "UseEvent.h"
#include "NonEquipCard.h"
#include "PrimitiveMoveEvent.h"
#include "MoveEvent.h"
#include "NeedUseEvent.h"
#include "ResolveEvent.h"

void UseEvent::execute()
{
    vector<MoveStruct*> moveData;
    Zone* targetZone=&game->resArea;
    CardType *name=data->data->info.name;
    if(name->type==Equip) targetZone=&data->data->player->equipArea;
    else if(name->isDelayedTrick) targetZone=&data->targets[0]->player->judgeArea;
    int i;
    data->data->testMove->happen();
    for(i=0;i<data->targets.size();i++) if(!name->isLegalTarget(data->targets[i]->player,data->data))
    {
        data->targets.erase(data->targets.begin()+i);
        i--;
    }
    if(!data->isLegal()) {data->data->testMove->undo();return;}
    data->data->testMove->undo();
    data->skills=name->getUseSkill(data);
    for(i=0;i<data->skills.size();i++) data->skills[i]->init();
    for(i=0;i<data->data->cards.size();i++) moveData.push_back(new MoveStruct(data->data->cards[i],targetZone));
    if(EquipCard *e=dynamic_cast<EquipCard*>(name))
    {
        Card* oldEquip=data->data->player->getEquip(e->equipType);
        if(oldEquip) moveData.push_back(new MoveStruct(oldEquip,&game->discardPile));
    }
    (new MoveEvent(moveData,this))->happen();
    if(data->data->cards.empty()||data->isSpecial) onTiming(specialUse);
    if(NeedUseEvent *need=dynamic_cast<NeedUseEvent*>(data->data->reason))
    {
        if(need->filter->filter(data->data->info))
        {
            need->fulfilled=true; //TODO: wrong target
            need->curTiming=nullTiming;
        }
    }
    success=true;
    if(name->type!=Equip)
    {
        onTiming(whenTarget);
        onTiming(whenTargeted);
        //TODO: cook the targets
        onTiming(afterTarget);
        onTiming(afterTargeted);
        if(!name->isDelayedTrick)
        {
            if(data->targets.empty()) data->targets.push_back(NULL);
            for(targetId=0;targetId<data->targets.size();targetId++)
                (new ResolveEvent(data,data->targets[targetId]))->happen();
            moveData.clear();
            for(i=0;i<data->data->cards.size();i++) if(data->data->cards[i]->zone==&game->resArea)
            {
                moveData.push_back(new MoveStruct(data->data->cards[i],&game->discardPile));
            }
            (new MoveEvent(moveData))->happen();
        }
    }
    onTiming(useCleanup);
    for(i=0;i<data->skills.size();i++) data->skills[i]->remove();
}

UseEvent::UseEvent(UseStruct *d):success(false)
{
    data=d;
}

UseEvent::~UseEvent()
{
    delete data;
}

string UseEvent::toString(Player *p)
{
    string res="use:";
    res+=data->data->toString();
    res+=":";
    for(int i=0;i<data->targets.size();i++)
    {
        TargetStruct *target=data->targets[i];
        res+=target->toString()+data->data->info.name->tagToString(target->tag)+";";
    }
    return res;
}
