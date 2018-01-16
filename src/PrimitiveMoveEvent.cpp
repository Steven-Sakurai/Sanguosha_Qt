#include "Lib.h"
#include "PrimitiveMoveEvent.h"
#include "EquipCard.h"

PrimitiveMoveEvent::PrimitiveMoveEvent(const vector<MoveStruct*> &d,MoveEvent *m)
{
    data=d;move=m;
    for(int i=0;i<data.size();i++)
    {
        newSkills.push_back(vector<SkillEffect*>());
        if(data[i]->dest->name=="equipArea")
        {
            if(EquipCard *eq=dynamic_cast<EquipCard*>(data[i]->card->getCardInfo().name))
                newSkills[i]=eq->getEquipSkill(data[i]->dest->player);
        }
    }
}

PrimitiveMoveEvent::~PrimitiveMoveEvent()
{
    int i;
    for(i=0;i<data.size();i++) delete data[i];
    for(i=0;i<newSkills.size();i++) for(int j=0;j<newSkills[i].size();j++) delete newSkills[i][j];
}

void PrimitiveMoveEvent::happen()
{
    int i;
    oldPos.clear();
    oldSkills.clear();
    for(i=0;i<data.size();i++)
	{
        MoveStruct* d=data[i];
        vector<SkillEffect*> t;
        int j;
        t.clear();
        for(j=d->card->skills.size()-1;j>=0;j--)
        {
            t.push_back(d->card->skills[j]);
            d->card->skills[j]->__remove();
        }
        oldSkills.push_back(t);
        d->card->skills.clear();
        oldPos.push_back(d->card->prev);
        if(d->inFront) d->dest->push_front(d->card);
        else d->dest->push_back(d->card);
        for(j=0;j<newSkills[i].size();j++)
        {
            newSkills[i][j]->__init();
            d->card->skills.push_back(newSkills[i][j]);
        }
    }
}

void PrimitiveMoveEvent::undo()
{
    for(int i=data.size()-1;i>=0;i--)
	{
        Card *c=data[i]->card;
        int j;
        for(j=newSkills[i].size()-1;j>=0;j--) newSkills[i][j]->__uninit();
        c->skills.clear();
        data[i]->card->move(oldPos[i]);
        for(j=0;j<oldSkills[i].size();j++)
        {
            oldSkills[i][j]->__unremove();
            c->skills.push_back(oldSkills[i][j]);
        }
    }
}

string PrimitiveMoveEvent::toString(Player *p)
{
    string res="move:";
    for(int i=0;i<data.size();i++)
    {
        MoveStruct *d=data[i];
        res+=d->card->toString(p)+"-"+d->dest->toString()+";";
    }
    return res;
}
