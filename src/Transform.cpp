#include "Lib.h"
#include "Transform.h"

Transform::Transform(Player *p)
{
    player=p;nRemoves=0;
}

void Transform::__init()
{
    for(int i=0;i<cardTypes.size();i++)
        player->transformTable[cardTypes[i]].push_back(this);
}

void Transform::__uninit()
{
    for(int i=0;i<cardTypes.size();i++)
        player->transformTable[cardTypes[i]].pop_back();
}

void Transform::__remove()
{
    if(!nRemoves++) for(int i=0;i<cardTypes.size();i++)
    {
        int j;
        vector<Transform*> &table=player->transformTable[cardTypes[i]];
        for(j=0;table[j]!=this;j++);
        oldPos.push_back(j);
        table.erase(table.begin()+j);
    }
}

void Transform::__unremove()
{
    if(!--nRemoves) for(int i=0;i<cardTypes.size();i++)
    {
        vector<Transform*> &table=player->transformTable[cardTypes[i]];
        table.insert(table.begin()+oldPos[i],this);
        oldPos.clear();
    }
}

bool Transform::canTransform(CardType *t, Event *e, TransformMode mode)
{
    return true;
}
