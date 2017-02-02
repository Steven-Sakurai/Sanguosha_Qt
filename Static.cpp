#include "Lib.h"
#include "Static.h"

Static::Static()
{
    priority=1;nRemoves=0;
}

void Static::__init()
{
    game->staticTable[influence][priority].push_back(this);
}

void Static::__uninit()
{
    game->staticTable[influence][priority].pop_back();
}

void Static::__remove()
{
    if(!nRemoves++)
    {
        int j;
        vector<Static*> &table=game->staticTable[influence][priority];
        for(j=0;table[j]!=this;j++);
        oldPos=j;
        table.erase(table.begin()+j);
    }
}

void Static::__unremove()
{
    if(!--nRemoves)
    {
        vector<Static*> &table=game->staticTable[influence][priority];
        table.insert(table.begin()+oldPos,this);
    }
}

string Static::toString()
{
    return "";
}
