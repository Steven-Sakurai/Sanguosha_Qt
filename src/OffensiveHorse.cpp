#include "Lib.h"
#include "OffensiveHorse.h"

OffensiveHorse::OffensiveHorse(string n) : EquipCard(n,OffHorse)
{
}

OffensiveHorse::~OffensiveHorse()
{
}

vector<SkillEffect *> OffensiveHorse::getEquipSkill(Player *p)
{
    return vector<SkillEffect*>(1,new OffensiveHorseSkill(p));
}


OffensiveHorseSkill::OffensiveHorseSkill(Player *p)
{
    player=p;influence=distanceValue;
}

void OffensiveHorseSkill::apply(void *value, void *data)
{
    int *v=(int*)value;
    pair<Player*,Player*> *d=(pair<Player*,Player*>*)data;
    if(d->first==player) (*v)--;
}
