/*
 * Zone.h
 * 
 */
#ifndef _ZONE_H
#define _ZONE_H

class Zone;

#include "Lib.h"
#include "Card.h"
#include "CardInfo.h"

class Player;

class Zone : public Card
{
public:
    string name;
    Player *player;
    bool isPublic;
	int size;
    Zone(string n, Player *p=NULL, bool pub=true , int x = 0 ,int y = 0) ;
	~Zone();
    void push_back(CardInfo *c);
    void push_front(CardInfo *c);
	void push_back(Card *n);
	void push_front(Card *n);
    bool isVisibleTo(Player *p);
    string toString();

    int zonePositionX;
    int zonePositionY;
};

#endif
