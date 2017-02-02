#ifndef USESTRUCT_H
#define USESTRUCT_H

#include "Lib.h"
#include "PreUseStruct.h"
#include "TargetStruct.h"

class UseStruct
{
public:
    PreUseStruct *data;
    vector<TargetStruct*> targets;
    bool isSpecial;
    vector<SkillEffect*> skills;
    UseStruct(PreUseStruct *d,const vector<Player*> &tar,bool sp=false);
    virtual ~UseStruct();
    bool isLegal();
};

#endif // USESTRUCT_H
