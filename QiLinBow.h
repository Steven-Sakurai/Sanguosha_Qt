#ifndef QILINBOW_H
#define QILINBOW_H

#include "Lib.h"
#include "WeaponCard.h"

class QiLinBow : public WeaponCard
{
public:
    QiLinBow();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class QiLinSkill : public Trigger
{
public:
    QiLinSkill(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // QILINBOW_H
