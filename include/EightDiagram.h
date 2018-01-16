#ifndef EIGHTDIAGRAM_H
#define EIGHTDIAGRAM_H

#include "Lib.h"
#include "EquipCard.h"

class EightDiagram : public EquipCard
{
public:
    EightDiagram();
    vector<SkillEffect*> getEquipSkill(Player *p);
};

class EightDiagramSkill : public Trigger
{
public:
    EightDiagramSkill(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // EIGHTDIAGRAM_H
