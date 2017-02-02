#ifndef ICESWORD_H
#define ICESWORD_H

#include "Lib.h"
#include "WeaponCard.h"

class IceSword : public WeaponCard
{
public:
    IceSword();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class IceSwordSkill : public Trigger
{
public:
    IceSwordSkill(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // ICESWORD_H
