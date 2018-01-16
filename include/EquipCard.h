#ifndef EQUIPCARD_H
#define EQUIPCARD_H

#include "Lib.h"
#include "CardType.h"
#include "SkillEffect.h"

enum EquipType
{
    Weapon,
    Armor,
    DefHorse,
    OffHorse
};

class EquipCard : public CardType
{
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    EquipType equipType;
    EquipCard(string n, EquipType et);
    bool use(PreUseStruct *d);
    virtual vector<SkillEffect*> getEquipSkill(Player *p)=0;
};

#endif // EQUIPCARD_H
