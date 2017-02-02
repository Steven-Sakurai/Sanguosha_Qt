#ifndef SPEAR_H
#define SPEAR_H

#include "Lib.h"
#include "WeaponCard.h"

class Spear : public WeaponCard
{
public:
    Spear();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class SpearSkill : public Transform
{
public:
    SpearSkill(Player *p);
    bool canTransform(CardType *t, Event *e, TransformMode mode);
    vector<Card*> chooseCards(CardType *t, Event *e);
    string toString(CardType *t);
};

#endif // SPEAR_H
