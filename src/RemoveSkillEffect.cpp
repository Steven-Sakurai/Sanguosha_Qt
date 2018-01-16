#include "Lib.h"
#include "RemoveSkillEffect.h"

RemoveSkillEffect::RemoveSkillEffect(SkillEffect *s)
{
    skill=s;
}

void RemoveSkillEffect::happen()
{
    skill->__remove();
}

void RemoveSkillEffect::undo()
{
    skill->__unremove();
}
