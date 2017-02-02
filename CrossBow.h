#ifndef CROSSBOW_H
#define CROSSBOW_H

#include "Lib.h"
#include "WeaponCard.h"

class CrossBow : public WeaponCard
{
public:
    CrossBow();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class CrossBowSkill : public Static
{
public:
    Player *player;
    CrossBowSkill(Player *p);
    void apply(void *value, void *data);
};

#endif // CROSSBOW_H
