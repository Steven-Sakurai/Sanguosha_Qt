#include "Lib.h"
#include "SkillEffect.h"
#include "RegisterSkillEffect.h"
#include "RemoveSkillEffect.h"

SkillEffect::SkillEffect()
{
}

SkillEffect::~SkillEffect()
{
}

void SkillEffect::init()
{
    game->doPrimitive(new RegisterSkillEffect(this));
}

void SkillEffect::remove()
{
    game->doPrimitive(new RemoveSkillEffect(this));
}
