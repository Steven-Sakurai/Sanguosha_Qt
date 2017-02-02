#ifndef REMOVESKILLEFFECT_H
#define REMOVESKILLEFFECT_H

#include "Lib.h"
#include "PrimitiveEvent.h"
#include "SkillEffect.h"

class RemoveSkillEffect : public PrimitiveEvent
{
protected:
    void happen();
    void undo();
public:
    SkillEffect *skill;
    RemoveSkillEffect(SkillEffect *s);
};

#endif // REMOVESKILLEFFECT_H
