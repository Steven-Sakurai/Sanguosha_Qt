#include "Lib.h"
#include "EightDiagram.h"
#include "Dodge.h"
#include "NeedUseEvent.h"
#include "NeedYieldEvent.h"
#include "JudgeEvent.h"
#include "YieldEvent.h"
#include "UseEvent.h"

EightDiagram::EightDiagram() : EquipCard("八卦阵",Armor)
{
}

vector<SkillEffect *> EightDiagram::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new EightDiagramSkill(p));
}

EightDiagramSkill::EightDiagramSkill(Player *p) : Trigger(p)
{
    timings.push_back(beforeResolve);timings.push_back(needUse);timings.push_back(needYield);priority=1;
}

vector<void *> EightDiagramSkill::getTrigger(Event *e, vector<void *> past)
{
    if(past.empty())
    {
        Timing t=e->curTiming;
        CardType *dodge=game->getCardType<Dodge>();
        NeedUseEvent *need=dynamic_cast<NeedUseEvent*>(e);
        NeedYieldEvent *need2=dynamic_cast<NeedYieldEvent*>(e);
        if(dodge->legalToUse(t,e,player)||need&&need->player==player&&need->filter->filter(CardInfo(dodge,0,0))
                ||need2&&need2->player==player&&need2->filter->filter(CardInfo(dodge,0,0)))
            return vector<void*>(1,(void*)NULL);
    }
    return vector<void*>();
}

bool EightDiagramSkill::trigger(Event *e, void *index)
{
    for(int i=0;i<game->nPlayer;i++) game->players[i]->inform(player->toString()+"发动了八卦阵");
    if((new JudgeEvent(player))->happen_getInfo().isRed())
    {
        Timing t=e->curTiming;
        CardType *dodge=game->getCardType<Dodge>();
        if(t==needYield) (new YieldEvent(player,vector<Card*>(),CardInfo(dodge,0,0),e,NULL))->happen();
        else (new PreUseStruct(player,vector<Card*>(),CardInfo(dodge,0,0),t,e,NULL))->use();
    }
    return true;
}

string EightDiagramSkill::toString(Event *e, void *index)
{
    return "八卦阵";
}
