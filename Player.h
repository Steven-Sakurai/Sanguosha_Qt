/*
 * Player.h
 * 
 */
#ifndef _PLAYER_H
#define _PLAYER_H

#include "Lib.h"
#include "ClientPlayer.h"
#include "Trigger.h"
#include "Transform.h"
#include "Zone.h"
#include "Card.h"
#include "EquipCard.h"
#include <map>

class Player
{
	ClientPlayer *client;
public:
    GameValue<Role> role;
	GameValue<bool> alive;
    GameValue<int> maxHp,hp;
	Zone hand,equipArea,judgeArea,onGeneral,byGeneral;
	vector<Trigger*> triggerTable[nTimings][3];
    map<CardType*, vector<Transform*> > transformTable;
    Player *nextPlayer;
    Player(ClientPlayer *c,Role r);
    void inform(string message);
    int getChoice(string reason, vector<string> choices);
    vector<int> getMultiChoice(string reason, const vector<string> &choices, int max=-1);
    vector<int> getMultiChoice(string reason, const vector<string> &choices, int max, const vector<bool> &mandatory);
    Card *chooseCard(string reason, const vector<Card *> &cards, string cancelString="");
    int getCurrentHp();
    int getLostHp();
    int getMaxHandSize();
    bool isMale();
    Card *getEquip(EquipType et);
    EquipCard *getEquipName(EquipType et);
    Player *getNextPlayer();
    int getDistanceTo(Player *p);
    int getRange();
	void draw(int n);
    bool canUse(Card *c,Timing t,Event *e);
    bool canYield(Card *c, Event *e);
    bool canUseAs(vector<Card*> c,CardInfo i,Timing t,Event *e);
    bool canYieldAs(vector<Card *> c, CardInfo i, Event *e);
	bool canDiscard(Card *c);
	void discard(vector<Card*> cards);
    string toString();
};

#endif
