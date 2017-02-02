#include "Lib.h"
#include "Dodge.h"
#include "Slash.h"

bool Dodge::canCounter(ResolveEvent *e, Player *p)
{
    return dynamic_cast<Slash*>(e->data->data->info.name)&&e->target->player==p;
}

Dodge::Dodge():CounterCard("闪",Basic)
{
}
