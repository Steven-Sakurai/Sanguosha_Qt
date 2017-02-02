#include "Lib.h"
#include "Spear.h"
#include "Slash.h"

Spear::Spear() : WeaponCard("丈八蛇矛",3)
{
}

vector<SkillEffect*> Spear::getEquipSkill(Player *p)
{
    return vector<SkillEffect*>(1,new SpearSkill(p));
}

SpearSkill::SpearSkill(Player *p) : Transform(p)
{
    cardTypes.push_back(game->getCardType<Slash>());
}

bool SpearSkill::canTransform(CardType *t, Event *e, TransformMode mode)
{
    return player->hand.size>=2;
}

vector<Card *> SpearSkill::chooseCards(CardType *t, Event *e)
{
    vector<Card*> cards,res;
    for(Card *c=player->hand.next;c!=&player->hand;c=c->next) cards.push_back(c);
    if(Card* res1=player->chooseCard("",cards,"取消"))
    {
        for(int i=0;i<cards.size();i++) if(cards[i]==res1)
        {
            cards.erase(cards.begin()+i);
            break;
        }
        if(Card* res2=player->chooseCard("",cards,"取消"))
        {
            res.push_back(res1);
            res.push_back(res2);
        }
    }
    return res;
}

string SpearSkill::toString(CardType *t)
{
    return "丈八蛇矛";
}
