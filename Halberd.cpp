#include "Lib.h"
#include "Halberd.h"
#include "PreUseStruct.h"
#include "Slash.h"

Halberd::Halberd() : WeaponCard("方天画戟",4)
{
}

vector<SkillEffect *> Halberd::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new HalberdSkill(p));
}

HalberdSkill::HalberdSkill(Player *p)
{
    player=p;influence=maxTargetValue;
}

void HalberdSkill::apply(void *value, void *data)
{
    int *v=(int*)value;
    PreUseStruct *d=(PreUseStruct*)data;
    if(d->player==player&&dynamic_cast<Slash*>(d->info.name)&&!d->cards.empty()&&!player->hand.size)
    {
        d->testMove->undo();
        bool flag=true;
        for(int i=0;i<d->cards.size();i++) if(d->cards[i]->zone!=&player->hand) flag=false;
        d->testMove->happen();
        if(flag) (*v)+=2;
    }
}
