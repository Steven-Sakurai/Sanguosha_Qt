#ifndef AXE_H
#define AXE_H

#include "Lib.h"
#include "WeaponCard.h"

class Axe : public WeaponCard
{
public:
    Axe();
    vector<SkillEffect*> getEquipSkill(Player *);
};

class AxeSkill : public Trigger
{
public:
    AxeSkill(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // AXE_H
