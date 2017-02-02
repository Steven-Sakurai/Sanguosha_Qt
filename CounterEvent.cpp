#include "Lib.h"
#include "CounterEvent.h"

void CounterEvent::execute()
{
    resolve->countered=true;
    onTiming(cardCountered);
}

CounterEvent::CounterEvent(ResolveEvent *r, UseStruct *d)
{
    resolve=r;data=d;
}
