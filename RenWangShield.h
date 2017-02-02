#ifndef RENWANGSHIELD_H
#define RENWANGSHIELD_H

#include "Lib.h"
#include "EquipCard.h"

class RenWangShield : public EquipCard
{
public:
    RenWangShield();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class RenWangSkill : public Static
{
public:
    Player *player;
    RenWangSkill(Player *p);
    void apply(void *value, void *data);
};

#endif // RENWANGSHIELD_H
