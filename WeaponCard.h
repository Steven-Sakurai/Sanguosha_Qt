#ifndef WEAPONCARD_H
#define WEAPONCARD_H

#include "Lib.h"
#include "EquipCard.h"

class WeaponCard : public EquipCard
{
public:
    int range;
    WeaponCard(string n, int r);
};

#endif // WEAPONCARD_H
