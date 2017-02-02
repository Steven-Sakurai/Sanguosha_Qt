#ifndef CIXIONGSWORD_H
#define CIXIONGSWORD_H

#include "Lib.h"
#include "WeaponCard.h"

class CiXiongSword : public WeaponCard
{
public:
    CiXiongSword();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class CiXiongSkill : public Trigger
{
public:
    CiXiongSkill(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // CIXIONGSWORD_H
