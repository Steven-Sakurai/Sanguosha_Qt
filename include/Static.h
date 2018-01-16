#ifndef STATIC_H
#define STATIC_H

#include "Lib.h"

class Static : public SkillEffect
{
    int nRemoves;
    int oldPos;
public:
    StaticValue influence;
    int priority;
    Static();
    void __init();
    void __uninit();
    void __remove();
    void __unremove();
    virtual void apply(void* value, void* data)=0;
    virtual string toString();
};

#endif // STATIC_H
