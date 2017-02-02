#include "Lib.h"
#include "NeedUseEvent.h"

void NeedUseEvent::execute()
{
    onTiming(needUse);
}

NeedUseEvent::NeedUseEvent(Player *p, CardFilter *f, vector<Player *> t) : fulfilled(false)
{
    player=p;filter=f;target=t;
}

NeedUseEvent::~NeedUseEvent()
{
    delete filter;
}

bool NeedUseEvent::happen_success()
{
    happen();
    return fulfilled;
}
