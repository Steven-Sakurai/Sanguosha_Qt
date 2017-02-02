#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Lib.h"
#include "SkillEffect.h"

class Player;

enum TransformMode
{
    transformUse,
    transformYield,
    transformRecast
};

class Transform : public SkillEffect
{
    int nRemoves;
    vector<int> oldPos;
public:
    Player *player;
    vector<CardType*> cardTypes;
    Transform(Player *p);
    void __init();
    void __uninit();
    void __remove();
    void __unremove();
    virtual bool canTransform(CardType *t, Event *e, TransformMode mode);
    virtual vector<Card*> chooseCards(CardType *t, Event *e)=0;
    virtual string toString(CardType *t)=0;
};

#endif // TRANSFORM_H
