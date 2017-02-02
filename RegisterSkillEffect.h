#ifndef REGISTERSKILLEFFECT_H
#define REGISTERSKILLEFFECT_H

#include "Lib.h"
#include "PrimitiveEvent.h"
#include "SkillEffect.h"

class RegisterSkillEffect : public PrimitiveEvent
{
protected:
    void happen();
    void undo();
public:
    SkillEffect *skill;
    RegisterSkillEffect(SkillEffect *s);
    ~RegisterSkillEffect();
};

#endif // REGISTERSKILLEFFECT_H
