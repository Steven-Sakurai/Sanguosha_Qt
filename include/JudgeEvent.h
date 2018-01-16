#ifndef JUDGEEVENT_H
#define JUDGEEVENT_H

#include "Lib.h"

class JudgeEvent : public Event
{
protected:
    void execute();
public:
    Player *player;
    Card *card;
    CardInfo info;
    JudgeEvent(Player *p);
    CardInfo happen_getInfo();
};

#endif // JUDGEEVENT_H
