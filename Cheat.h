#ifndef CHEAT_H
#define CHEAT_H

#include "Lib.h"

class Cheat : public Trigger
{
public:
    Cheat(Player *p);
    vector<void*> getTrigger(Event *e, vector<void *> past);
    bool trigger(Event *e, void *index);
    string toString(Event *e, void *index);
};

#endif // CHEAT_H
