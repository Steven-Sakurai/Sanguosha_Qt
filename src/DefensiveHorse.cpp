#include "Lib.h"
#include "DefensiveHorse.h"

DefensiveHorse::DefensiveHorse(string n) : EquipCard(n,DefHorse)
{
}

DefensiveHorse::~DefensiveHorse()
{
}

vector<SkillEffect *> DefensiveHorse::getEquipSkill(Player *p)
{
    return vector<SkillEffect*>(1,new DefensiveHorseSkill(p));
}


DefensiveHorseSkill::DefensiveHorseSkill(Player *p)
{
    player=p;influence=distanceValue;
}

void DefensiveHorseSkill::apply(void *value, void *data)
{
    int *v=(int*)value;
    pair<Player*,Player*> *d=(pair<Player*,Player*>*)data;
    if(d->second==player) (*v)++;
}
