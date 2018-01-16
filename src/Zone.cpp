#include "Lib.h"
Zone::Zone(string n, Player *p, bool pub ,int x , int y )
{
    zone=this;name=n;player=p;isPublic=pub;size=0;info=NULL;prev=next=this;
}

Zone::~Zone()
{
	while(next!=this) delete next;
}

void Zone::push_back(CardInfo *c)
{
    new Card(c,prev);
}

void Zone::push_front(CardInfo *c)
{
	new Card(c,this);
}

void Zone::push_back(Card *n)
{
	n->move(prev);
}

void Zone::push_front(Card *n)
{
    n->move(this);
}

bool Zone::isVisibleTo(Player *p)
{
    return isPublic||this==&p->hand;
}

string Zone::toString()
{
    if(player==NULL) return name;
    return name+":"+player->toString();
}
