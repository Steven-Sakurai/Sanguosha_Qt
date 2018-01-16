#include "Lib.h"
#include "DeathEvent.h"
#include "DiscardEvent.h"
#include "MoveEvent.h"

void DeathEvent::execute()
{
    player->alive=false;
    if(game->curTurn->player==player) game->curTurn->end();
    //TODO: no longer any card's target
    onTiming(beforeRevealRole);
    for(int i=0;i<game->nPlayer;i++)
    {
        Player *p=game->players[i];
        ostringstream s;
        s<<"death_role:"<<player->toString()<<":"<<player->role;
        p->inform(s.str());
    }
    if(player->role==Lord)
    {
        bool t=false;
        for(int i=0;i<game->nPlayer;i++)
        {
            Player *p=game->players[i];
            if(p->alive)
            {
                if(p->role!=Renegade||t) throw GameOverException(rebelWin);
                t=true;
            }
        }
        throw GameOverException(renegadeWin);
    }
    else if(player->role==Rebel||player->role==Renegade)
    {
        int i;
        for(i=0;i<game->nPlayer;i++)
        {
            Player *p=game->players[i];
            if(p->alive&&(p->role==Rebel||p->role==Renegade)) break;
        }
        if(i==game->nPlayer) throw GameOverException(lordWin);
    }
    onTiming(onDeath);
    //TODO: remove all skills
    vector<Card*> cards;
    Card* c;
    for(c=player->hand.next;c!=&player->hand;c=c->next) cards.push_back(c);
    for(c=player->equipArea.next;c!=&player->equipArea;c=c->next) cards.push_back(c);
    for(c=player->judgeArea.next;c!=&player->judgeArea;c=c->next) cards.push_back(c);
    (new DiscardEvent(NULL,cards))->happen();
    vector<MoveStruct*> data;
    for(c=player->onGeneral.next;c!=&player->onGeneral;c=c->next)
        data.push_back(new MoveStruct(c,&game->discardPile));
    for(c=player->byGeneral.next;c!=&player->byGeneral;c=c->next)
        data.push_back(new MoveStruct(c,&game->discardPile));
    (new MoveEvent(data))->happen();
    //TODO: general card
    if(Player *killer=getKiller())
    {
        if(player->role==Rebel) killer->draw(3);
        else if(player->role==Loyalist&&killer->role==Lord)
        {
            cards.clear();
            for(c=killer->hand.next;c!=&killer->hand;c=c->next) cards.push_back(c);
            for(c=killer->equipArea.next;c!=&killer->equipArea;c=c->next) cards.push_back(c);
            killer->discard(cards);
        }
    }
    onTiming(afterDeath);
}

DeathEvent::DeathEvent(Player *p, DamageEvent *d)
{
    player=p;damage=d;
}

Player *DeathEvent::getKiller()
{
    if(!damage) return NULL;
    return damage->source;
}

string DeathEvent::toString(Player *p)
{
    string res="death:";
    res+=player->toString();
    return res;
}
