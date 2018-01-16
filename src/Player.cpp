#include "Lib.h"
#include "Player.h"
#include "MoveEvent.h"
#include "DiscardEvent.h"
#include "CardType.h"
#include "WeaponCard.h"
#include "NeedUseEvent.h"
#include "NeedYieldEvent.h"

Player::Player(ClientPlayer *c,Role r):role(r),alive(true),maxHp(4),hp(maxHp),
    hand("hand",this,false),equipArea("equipArea",this),judgeArea("judgeArea",this),
    onGeneral("onGeneral",this),byGeneral("byGeneral",this)
  //TODO: should need General
{
    client=c;
}

string Player::toString()
{
    for(int i=0;i<game->nPlayer;i++) if(game->players[i]==this)
    {
        ostringstream s;
        s<<"Player "<<i;
        return s.str();
    }
    return "";
    //TODO: should return General name
}

void Player::inform(string message)
{
    client->inform(message);
}

int Player::getChoice(string reason, vector<string> choices)
{
    return client->getChoice(reason, choices);
}

vector<int> Player::getMultiChoice(string reason, const vector<string> &choices, int max)
{
    return getMultiChoice(reason, choices, max, vector<bool>(choices.size(),false));
}

vector<int> Player::getMultiChoice(string reason, const vector<string> &choices, int max, const vector<bool> &mandatory)
{
    return client->getMultiChoice(reason, choices, max, mandatory);
}

Card* Player::chooseCard(string reason, const vector<Card*> &cards, string cancelString)
{
    vector<string> choices;
    vector<int> results;
    int i;
    string choice;
    for(i=0;i<cards.size();i++) choices.push_back(cards[i]->toString(this));
    if(!cancelString.empty()) choices.push_back("cancel@"+cancelString);
    i=getChoice("card:"+reason,choices);
    if(i<cards.size())
    {
        choice=choices[i];
        for(int i=0;i<cards.size();i++) if(choices[i]==choice) results.push_back(i);
        return cards[results[rand()%results.size()]];
    }
    return NULL;
}

int Player::getCurrentHp()
{
    return hp>0?int(hp):0;
}

int Player::getLostHp()
{
    return maxHp-getCurrentHp();
}

int Player::getMaxHandSize()
{
    return getCurrentHp();
}

Card *Player::getEquip(EquipType et)
{
    for(Card *c=equipArea.next;c!=&equipArea;c=c->next)
    {
        EquipCard *e=dynamic_cast<EquipCard*>(c->getCardInfo().name);
        if(e->equipType==et) return c;
    }
    return NULL;
}

EquipCard *Player::getEquipName(EquipType et)
{
    for(Card *c=equipArea.next;c!=&equipArea;c=c->next)
    {
        EquipCard *e=dynamic_cast<EquipCard*>(c->getCardInfo().name);
        if(e->equipType==et) return e;
    }
    return NULL;
}

Player* Player::getNextPlayer()
{
    Player* res=nextPlayer;
    while(!res->alive) res=res->nextPlayer;
    return res;
}

int Player::getDistanceTo(Player *p)
{
    if(!alive||!p->alive) return -1;
    if(p==this) return 0;
    int dist1=0,dist2=0;
    Player *t;
    for(t=this;t!=p;t=t->getNextPlayer()) dist1++;
    for(t=p;t!=this;t=t->getNextPlayer()) dist2++;
    int res=dist1<dist2?dist1:dist2;
    pair<Player*,Player*> data=make_pair(this,p);
    game->applyStatics(distanceValue,&res,&data);
    if(res<1) return 1;
    return res;
}

int Player::getRange()
{
    WeaponCard *w=dynamic_cast<WeaponCard*>(getEquipName(Weapon));
    if(w) return w->range;
    return 1;//TODO: Skills like 吴六剑
}

bool Player::isMale()
{
    return toString()[7]%2;//test
}

void Player::draw(int n)
{
    if(!alive) return;
	vector<Card*> cards=game->getTopCards(n);
	vector<MoveStruct*> d;
	for(int i=0;i<n;i++) d.push_back(new MoveStruct(cards[i],&hand));
    (new MoveEvent(d))->happen();
}

bool Player::canUse(Card *c,Timing t,Event *e)
{
    return canUseAs(vector<Card*>(1,c),c->getCardInfo(),t,e);
}

bool Player::canYield(Card *c, Event *e)
{
    return canYieldAs(vector<Card*>(1,c),c->getCardInfo(),e);
}

bool Player::canUseAs(vector<Card*> c,CardInfo i,Timing t,Event *e)
{
    bool res;
    if(NeedUseEvent *need=dynamic_cast<NeedUseEvent*>(e)) res=!need->fulfilled&&need->player==this&&need->filter->filter(i);
    else res=i.name->legalToUse(t,e,this);
    return res;//TODO: Skills like 鸡肋
}

bool Player::canYieldAs(vector<Card*> c,CardInfo i,Event *e)
{
    bool res=true;
    if(NeedYieldEvent *need=dynamic_cast<NeedYieldEvent*>(e)) res=!need->fulfilled&&need->player==this&&need->filter->filter(i);
    return res;//TODO: Skills like 鸡肋
}

bool Player::canDiscard(Card *c)
{
    return c&&alive;//TODO: Skills like 鸡肋
}

void Player::discard(vector<Card*> cards)
{
    (new DiscardEvent(this,cards))->happen();
}
