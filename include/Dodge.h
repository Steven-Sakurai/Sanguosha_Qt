#ifndef DODGE_H
#define DODGE_H

#include "CounterCard.h"

class Dodge : public CounterCard
{
    bool canCounter(ResolveEvent *e, Player *p);
public:
    Dodge();
};

#endif // DODGE_H
