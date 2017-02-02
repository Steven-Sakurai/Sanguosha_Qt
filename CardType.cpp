#include "Lib.h"
#include "CardType.h"
#include "PhaseEvent.h"

bool CardType::distanceCheck(Player *target, PreUseStruct *d)
{
    return true;
}

CardType::CardType(string n, Type t)
{
    name=n;type=t;isDelayedTrick=false;
}

CardType::~CardType() {}

bool CardType::legalToUse(Timing t,Event *e,Player *p)
{
    return p->alive&&canBeUsed(t,e,p);//TODO: skills like 完杀
}

bool CardType::canBeUsed(Timing t,Event *e,Player *p)
{
    return t==doMainPhase;
}

bool CardType::isLegalTarget(Player *target, PreUseStruct *d)
{
    return target->alive&&legalityCheck(target,d)&&distanceCheck(target,d);
    //TODO: "No distance limit" skills and skills like 空城
}

bool CardType::isLegalTarget(Player *target, Player *user)
{
    PreUseStruct *temp=new PreUseStruct(user,this);
    bool res=isLegalTarget(target,temp);
    delete temp;
    return res;
}

bool CardType::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return false;
    //TODO: effects like 借刀杀人's
}

vector<SkillEffect *> CardType::getUseSkill(UseStruct *d)
{
    return vector<SkillEffect *>();
}

string CardType::tagToString(void *tag)
{
    return "";
}
