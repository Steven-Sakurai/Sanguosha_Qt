#include "Lib.h"
#include "Trigger.h"

Trigger::Trigger(Player *p)
{
    player=p;priority=0;isMandatory=false;nRemoves=0;
}

void Trigger::__init()
{
    for(int i=0;i<timings.size();i++)
        player->triggerTable[timings[i]][priority].push_back(this);
}

void Trigger::__uninit()
{
    for(int i=0;i<timings.size();i++)
        player->triggerTable[timings[i]][priority].pop_back();
}

void Trigger::__remove()
{
    if(!nRemoves++) for(int i=0;i<timings.size();i++)
    {
        int j;
        vector<Trigger*> &table=player->triggerTable[timings[i]][priority];
        for(j=0;table[j]!=this;j++);
        oldPos.push_back(j);
        table.erase(table.begin()+j);
    }
}

void Trigger::__unremove()
{
    if(!--nRemoves) for(int i=0;i<timings.size();i++)
    {
        vector<Trigger*> &table=player->triggerTable[timings[i]][priority];
        table.insert(table.begin()+oldPos[i],this);
        oldPos.clear();
    }
}
