#ifndef HARVEST_H
#define HARVEST_H

#include "Lib.h"
#include "NonEquipCard.h"

class Harvest : public NonEquipCard
{
protected:
    bool legalityCheck(Player *target, PreUseStruct *d);
public:
    Harvest();
    void resolve(TargetStruct *target, UseStruct *d);
    bool isMandatoryTarget(Player *target, PreUseStruct *d);
    vector<SkillEffect*> getUseSkill(UseStruct *d);
};

class HarvestInit : public Trigger
{
public:
    UseStruct *data;
    vector<Card*> cards;
    HarvestInit(UseStruct *d);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

class HarvestCleanup : public Trigger
{
public:
    UseStruct *data;
    HarvestCleanup(UseStruct *d);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // HARVEST_H
