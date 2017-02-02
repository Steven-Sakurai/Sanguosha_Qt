#include "Lib.h"
#include "QiLinBow.h"
#include "DamageEvent.h"
#include "Slash.h"

QiLinBow::QiLinBow() : WeaponCard("麒麟弓",5)
{
}

vector<SkillEffect *> QiLinBow::getEquipSkill(Player *p)
{
    return vector<SkillEffect *>(1,new QiLinSkill(p));
}

QiLinSkill::QiLinSkill(Player *p) : Trigger(p)
{
    timings.push_back(afterDamage);priority=1;
}

vector<void *> QiLinSkill::getTrigger(Event *e, vector<void *> past)
{
    DamageEvent *damage=dynamic_cast<DamageEvent*>(e);
    if(past.empty()&&damage->source==player&&dynamic_cast<Slash*>(damage->reason->data->info.name))
    {
        Card *o=damage->player->getEquip(OffHorse),*d=damage->player->getEquip(DefHorse);
        if(player->canDiscard(o)||player->canDiscard(d)) return vector<void*>(1,(void*)NULL);
    }
    return vector<void*>();
}

bool QiLinSkill::trigger(Event *e, void *index)
{
    DamageEvent *damage=dynamic_cast<DamageEvent*>(e);
    for(int i=0;i<game->nPlayer;i++) game->players[i]->inform(player->toString()+"发动了麒麟弓");
    Card *o=damage->player->getEquip(OffHorse),*d=damage->player->getEquip(DefHorse);
    vector<Card*> cards;
    if(player->canDiscard(o)) cards.push_back(o);
    if(player->canDiscard(d)) cards.push_back(d);
    player->discard(vector<Card*>(1,player->chooseCard("discard:你发动了麒麟弓",cards)));
    return true;
}

string QiLinSkill::toString(Event *e, void *index)
{
    return "麒麟弓";
}
