#ifndef MOVEVISIBILITYEFFECT_H
#define MOVEVISIBILITYEFFECT_H

#include "Lib.h"
#include "Static.h"
#include "MoveEvent.h"

class MoveVisibilityEffect : public Static
{
    bool trying;
public:
    MoveEvent *event;
    MoveVisibilityEffect(MoveEvent *e);
    void apply(void *value, void *data);
};

#endif // MOVEVISIBILITYEFFECT_H
