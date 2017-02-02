#ifndef OFFENSIVEHORSE_H
#define OFFENSIVEHORSE_H

#include "Lib.h"
#include "EquipCard.h"

class OffensiveHorse : public EquipCard
{
public:
    OffensiveHorse(string n);
    virtual ~OffensiveHorse();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class OffensiveHorseSkill: public Static
{
public:
    Player *player;
    OffensiveHorseSkill(Player *p);
    void apply(void *value, void *data);
};

#endif // OFFENSIVEHORSE_H
