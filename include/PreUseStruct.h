#ifndef PREUSESTRUCT_H
#define PREUSESTRUCT_H

#include "Lib.h"
class Player;
class Card;
#include "CardInfo.h"
#include "PrimitiveMoveEvent.h"

class PreUseStruct
{
public:
    Player *player;
    vector<Card*> cards;
    CardInfo info;
    Timing timing;
    Event *reason;
    Transform *transform;
    PrimitiveMoveEvent *testMove;
    PreUseStruct(Player *p, const vector<Card*> &c, CardInfo i, Timing t, Event *r, Transform *trans);
    PreUseStruct(Player *p,Card *c,Timing t,Event *r);
    PreUseStruct(Player *p, CardType *ct);
    ~PreUseStruct();
    bool use();
    bool isLegal();
    int getMaxTargets();
    string toString();
};

#endif // PREUSESTRUCT_H
