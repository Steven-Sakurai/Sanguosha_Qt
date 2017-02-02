#include "DiscardEvent.h"
#include "MoveEvent.h"

void DiscardEvent::execute()
{
    vector<MoveStruct*> d;
    for(int i=0;i<cards.size();i++)
    {
        if(!player||player->canDiscard(cards[i])) d.push_back(new MoveStruct(cards[i],&game->discardPile)); //TODO:reveal
    }
    (new MoveEvent(d,this))->happen();
}

DiscardEvent::DiscardEvent(Player *p, const vector<Card *> &c)
{
	player=p;
    cards=c;
}
