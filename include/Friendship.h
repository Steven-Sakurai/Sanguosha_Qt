#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

#include "Lib.h"
#include "NonEquipCard.h"

class Friendship : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Friendship();
    void resolve(TargetStruct *target, UseStruct *d);
    bool isMandatoryTarget(Player *target, PreUseStruct *d);
    vector<SkillEffect*> getUseSkill(UseStruct *d);
};

class FriendshipEffectiveness : public Static
{
public:
    UseStruct *use;
    FriendshipEffectiveness(UseStruct *d);
    void apply(void *value, void *data);
};

#endif // FRIENDSHIP_H
