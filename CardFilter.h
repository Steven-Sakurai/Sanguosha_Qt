#ifndef CARDFILTER_H
#define CARDFILTER_H

#include "Lib.h"

class CardFilter
{
public:
	
    virtual bool filter(CardInfo c)=0;
    virtual ~CardFilter() {}
};

template <class T> class NameFilter : public CardFilter
{
public:
    bool filter(CardInfo c) {return dynamic_cast<T*>(c.name);}
};

#endif // CARDFILTER_H
