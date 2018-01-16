#ifndef SKILLEFFECT_H
#define SKILLEFFECT_H

#include "Lib.h"

class SkillEffect
{
public:
    SkillEffect();
    virtual ~SkillEffect();
    void init();
    void remove();
    virtual void __init()=0;
    virtual void __uninit()=0;
    virtual void __remove()=0;
    virtual void __unremove()=0;
};

#endif // SKILLEFFECT_H
