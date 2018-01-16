#include "Lib.h"
#include "PrimitiveMoveEvent.h"
#include "MoveEvent.h"
#include "MoveVisibilityEffect.h"

void MoveEvent::execute()
{
    if(data.empty()) return;
    onTiming(beforeMove);
    MoveVisibilityEffect *v=new MoveVisibilityEffect(this);
    v->init();
    onTiming(whenMove);
    game->doPrimitive(new PrimitiveMoveEvent(data,this));
    v->remove();
    if(game->deck.size==0) game->shuffle();
    onTiming(afterMove);
}

MoveEvent::MoveEvent(const vector<MoveStruct *> &d, Event *r)
{
	data=d;
    reason=r;
}
