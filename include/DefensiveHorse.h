#ifndef DEFENSIVEHORSE_H
#define DEFENSIVEHORSE_H

#include "Lib.h"
#include "EquipCard.h"

class DefensiveHorse : public EquipCard
{
public:
    DefensiveHorse(string n);
    virtual ~DefensiveHorse();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class DefensiveHorseSkill: public Static
{
public:
    Player *player;
    DefensiveHorseSkill(Player *p);
    void apply(void *value, void *data);
};

#endif // DEFENSIVEHORSE_H
