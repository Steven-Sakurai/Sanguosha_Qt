#include "Lib.h"
#include "CrossBow.h"

CrossBow::CrossBow() : WeaponCard("诸葛连弩",1)
{
}

vector<SkillEffect *> CrossBow::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new CrossBowSkill(p));
}

CrossBowSkill::CrossBowSkill(Player *p)
{
    player=p;influence=slashLimitApplied;
}

void CrossBowSkill::apply(void *value, void *data)
{
    *(bool*)value=false;
}
