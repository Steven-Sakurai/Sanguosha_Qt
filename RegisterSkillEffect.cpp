#include "Lib.h"
#include "RegisterSkillEffect.h"

RegisterSkillEffect::RegisterSkillEffect(SkillEffect *s)
{
    skill=s;
}

RegisterSkillEffect::~RegisterSkillEffect()
{
    delete skill;
}

void RegisterSkillEffect::happen()
{
    skill->__init();
}

void RegisterSkillEffect::undo()
{
    skill->__uninit();
}
