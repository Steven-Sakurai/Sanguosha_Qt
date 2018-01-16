#include "Lib.h"
#include "RenWangShield.h"
#include "ResolveEvent.h"
#include "Slash.h"

RenWangShield::RenWangShield() : EquipCard("仁王盾",Armor)
{
}

vector<SkillEffect *> RenWangShield::getEquipSkill(Player *p)
{
    return vector<SkillEffect*>(1,new RenWangSkill(p));
}

RenWangSkill::RenWangSkill(Player *p)
{
    player=p;influence=useEffectiveness;
}

void RenWangSkill::apply(void *value, void *data)
{
    bool *v=(bool*)value;
    ResolveEvent *d=(ResolveEvent*)data;
    CardInfo info=d->data->data->info;
    if(dynamic_cast<Slash*>(info.name)&&info.isBlack()&&d->target->player==player) *v=false;
}
