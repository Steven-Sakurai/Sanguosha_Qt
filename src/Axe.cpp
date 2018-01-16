#include "Lib.h"
#include "Axe.h"
#include "CounterEvent.h"
#include "Slash.h"
#include "Dodge.h"

Axe::Axe() : WeaponCard("贯石斧",3)
{
}

vector<SkillEffect *> Axe::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new AxeSkill(p));
}


AxeSkill::AxeSkill(Player *p) : Trigger(p)
{
    timings.push_back(cardCountered);priority=1;
}

vector<void *> AxeSkill::getTrigger(Event *e, vector<void *> past)
{
    CounterEvent *counter=dynamic_cast<CounterEvent*>(e);
    if(past.empty()&&counter->resolve->data->data->player==player
            &&dynamic_cast<Slash*>(counter->resolve->data->data->info.name)
            &&dynamic_cast<Dodge*>(counter->data->data->info.name)) return vector<void*>(1,(void*)NULL);
    return vector<void*>();
}

bool AxeSkill::trigger(Event *e, void *index)
{
    vector<Card*> cards,res;
    for(Card *c=player->hand.next;c!=&player->hand;c=c->next) cards.push_back(c);
    for(Card *c=player->equipArea.next;c!=&player->equipArea;c=c->next)
    {
        int i;
        for(i=0;i<c->skills.size();i++) if(c->skills[i]==this) break;
        if(i==c->skills.size()) cards.push_back(c);
    }
    if(Card* res1=player->chooseCard("discard:你发动了贯石斧",cards,"取消"))
    {
        for(int i=0;i<cards.size();i++) if(cards[i]==res1)
        {
            cards.erase(cards.begin()+i);
            break;
        }
        if(Card* res2=player->chooseCard("discard:你发动了贯石斧",cards,"取消"))
        {
            res.push_back(res1);
            res.push_back(res2);
        }
    }
    if(res.empty()) return false;
    for(int i=0;i<game->nPlayer;i++) game->players[i]->inform(player->toString()+"发动了贯石斧");
    player->discard(res);
    CounterEvent *counter=dynamic_cast<CounterEvent*>(e);
    counter->resolve->countered=false;
    return true;
}

string AxeSkill::toString(Event *e, void *index)
{
    return "贯石斧";
}



