/*
 * Trigger.h
 * 
 */
#ifndef _TRIGGER_H
#define _TRIGGER_H

#include "Lib.h"
#include "Event.h"
#include "SkillEffect.h"

class Player;

class Trigger : public SkillEffect
{
    int nRemoves;
    vector<int> oldPos;
public:
    Player *player;
    vector<Timing> timings;
    int priority;
    bool isMandatory;
    Trigger(Player *p);
    void __init();
    void __uninit();
    void __remove();
    void __unremove();
    virtual vector<void*> getTrigger(Event *e, vector<void*> past)=0;
    virtual bool trigger(Event *e, void* index)=0;
    virtual string toString(Event *e, void* index)=0;
};
#endif
