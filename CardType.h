#ifndef CARDTYPE_H
#define CARDTYPE_H

#include "Lib.h"
#include "PreUseStruct.h"
#include "UseStruct.h"
class Player;
class Card;

enum Type
{
    Basic,//基本牌
    Trick,//锦囊牌
    Equip//装备牌
};

class CardType
{
protected:
    virtual bool legalityCheck(Player *target,PreUseStruct *d)=0;//合法性检查
    virtual bool distanceCheck(Player *target,PreUseStruct *d);//距离检查
    virtual bool canBeUsed(Timing t, Event *e, Player *p);
public:
    int maxTargets;//最大目标数
    string name;//牌名
    string Engname;//英文名
    Type type;//类型
    bool isDelayedTrick;//是否延迟类锦囊?
    CardType(string n,Type t);//构造函数:牌名,类别
    virtual ~CardType();
    bool legalToUse(Timing t, Event *e, Player *p);//使用合法?
    virtual bool use(PreUseStruct *d)=0;
    bool isLegalTarget(Player *target, PreUseStruct *d);
    bool isLegalTarget(Player *target, Player *user);
    virtual bool isMandatoryTarget(Player *target, PreUseStruct *d);
    virtual vector<SkillEffect*> getUseSkill(UseStruct *d);
    virtual string tagToString(void *tag);
};

#endif // CARDTYPE_H
