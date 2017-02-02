#include "Lib.h"
#include "PhaseEvent.h"
#include "MoveEvent.h"
#include "ResolveEvent.h"

void PhaseEvent::execute()
{
    onTiming(beginPhase);
    switch(phase)
    {
    case standbyPhase: case cleanupPhase: break;
    case judgePhase:
    {
        vector<Card*> delayedTricks;
        Card *c;
        for(c=player->judgeArea.prev;c!=&player->judgeArea;c=c->prev) delayedTricks.push_back(c);
        for(int i=0;i<delayedTricks.size();i++)
        {
            c=delayedTricks[i];
            UseStruct *d=new UseStruct(new PreUseStruct(NULL,c,nTimings,this),vector<Player*>(1,player));
            (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(c,&game->resArea))))->happen();
            (new ResolveEvent(d,d->targets[0]))->happen();
            if(c->zone==&game->resArea)
                (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(c,&game->discardPile))))->happen();
        }
        break;
    }
    case drawPhase:
        //TODO
        player->draw(2);
        //TODO
        break;
    case mainPhase:
        onTiming(doMainPhase);
    case discardPhase:
        while(player->hand.size>player->getMaxHandSize())
        {
            vector<Card*> cards;
            cards.clear();
            for(Card *c=player->hand.next;c!=&player->hand;c=c->next) if(player->canDiscard(c)) cards.push_back(c);
            player->discard(vector<Card*>(1,player->chooseCard("discard:discard_phase",cards)));
        }
        break;
    }
    onTiming(endPhase);
}

PhaseEvent::PhaseEvent(Player *p, Phase ph)
{
	player=p;phase=ph;
	game->curTurn->curPhase=this;
}

void PhaseEvent::end()
{
	curTiming=nullTiming;
}
