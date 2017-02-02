#include "Lib.h"
#include "IceSword.h"
#include "DamageEvent.h"
#include "Slash.h"

IceSword::IceSword() : WeaponCard("寒冰剑",2)
{
}

vector<SkillEffect *> IceSword::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new IceSwordSkill(p));
}

IceSwordSkill::IceSwordSkill(Player *p) : Trigger(p)
{
    timings.push_back(whenDamage);priority=1;
}

vector<void *> IceSwordSkill::getTrigger(Event *e, vector<void *> past)
{
    DamageEvent *damage=dynamic_cast<DamageEvent*>(e);
    if(past.empty()&&damage->source==player&&dynamic_cast<Slash*>(damage->reason->data->info.name))
    {
        Card *c;
        Player *target=damage->player;
        for(c=target->hand.next;c!=&target->hand;c=c->next) if(player->canDiscard(c)) return vector<void*>(1,(void*)NULL);
        for(c=target->equipArea.next;c!=&target->equipArea;c=c->next) if(player->canDiscard(c)) return vector<void*>(1,(void*)NULL);
    }
    return vector<void*>();
}

bool IceSwordSkill::trigger(Event *e, void *index)
{
    DamageEvent *damage=dynamic_cast<DamageEvent*>(e);
    Player *target=damage->player;
    vector<Card*> cards;
    int i;
    for(i=0;i<game->nPlayer;i++) game->players[i]->inform(player->toString()+"发动寒冰剑，防止此伤害");
    damage->prevent();
    for(i=0;i<2;i++)
    {
        Card *c;
        cards.clear();
        for(c=target->hand.next;c!=&target->hand;c=c->next) if(player->canDiscard(c)) cards.push_back(c);
        for(c=target->equipArea.next;c!=&target->equipArea;c=c->next) if(player->canDiscard(c)) cards.push_back(c);
        if(cards.empty()) break;
        player->discard(vector<Card*>(1,player->chooseCard("discard:你发动了寒冰剑",cards)));
    }
    return true;
}

string IceSwordSkill::toString(Event *e, void *index)
{
    return "寒冰剑";
}
