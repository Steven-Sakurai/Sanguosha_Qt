#include "Lib.h"
#include "NeedYieldEvent.h"

void NeedYieldEvent::execute()
{
    onTiming(needYield);
}

NeedYieldEvent::NeedYieldEvent(Player *p, CardFilter *f):fulfilled(false)
{
    player=p;filter=f;
}

NeedYieldEvent::~NeedYieldEvent()
{
    delete filter;
}

bool NeedYieldEvent::happen_success()
{
    happen();
    return fulfilled;
}
