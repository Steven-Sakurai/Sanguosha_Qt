#include "Lib.h"
#include "WeaponCard.h"

WeaponCard::WeaponCard(string n, int r) : EquipCard(n,Weapon)
{
    range=r;
}
