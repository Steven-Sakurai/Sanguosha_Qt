#ifndef TARGETSTRUCT_H
#define TARGETSTRUCT_H

#include "Lib.h"

class TargetStruct
{
public:
    Player *player;
    GameValue<bool> valid;
    void* tag;
    TargetStruct(Player *p);
    string toString();
};

#endif // TARGETSTRUCT_H
