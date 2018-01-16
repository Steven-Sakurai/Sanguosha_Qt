#ifndef HALBERD_H
#define HALBERD_H

#include "Lib.h"
#include "WeaponCard.h"

class Halberd : public WeaponCard
{
public:
    Halberd();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class HalberdSkill : public Static
{
public:
    Player *player;
    HalberdSkill(Player *p);
    void apply(void *value, void *data);
};

#endif // HALBERD_H
