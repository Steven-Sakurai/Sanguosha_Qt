/*
 * Game.h
 * 
 */
#ifndef _GAME_H
#define _GAME_H

class Game;

template <class T> class GameValue
{
public:
	T value;
    GameValue() {}
    GameValue(T v) {value=v;}
	GameValue& operator=(const T& rhs);
    GameValue& operator+=(const T& rhs) {return operator=(value+rhs);}
    GameValue& operator-=(const T& rhs) {return operator=(value-rhs);}
	operator T() const {return value;}
};

#include "Lib.h"
#include "ClientPlayer.h"
#include "Event.h"
#include "GamePointer.h"
#include "PrimitiveEvent.h"
#include "ValueChangeEvent.h"
#include "Zone.h"
#include "Player.h"
#include "TurnEvent.h"
#include "SkillEffect.h"
#include "Static.h"
#include <map>
#include <typeinfo>
#include "mainwindow.h"

class Game
{
public:
    int nPlayer;
    vector<CardType*> cardTypes;
	GameValue<int> curPlayer;
	GamePointer<TurnEvent> curTurn;
	vector<Player*> players;
	Zone deck,discardPile,resArea;
	vector<PrimitiveEvent*> timeline;
    vector<Event*> stack;
    vector<Static*> staticTable[nStaticValues][3];
    Game(const vector<ClientPlayer *> &clients, bool cheatMode=false,MainWindow * w = 0);
    ~Game();
    template <class T> CardType* getCardType()
    {
        for(int i=0;i<cardTypes.size();i++) if(typeid(*cardTypes[i])==typeid(T)) return cardTypes[i];
        cardTypes.push_back(new T());
        return cardTypes.back();
    }
    void handleTiming(Timing t, Event *e, int i=-1);
    void applyStatics(StaticValue sv, void *value, void *data);
	void doPrimitive(PrimitiveEvent *pe);
	void shuffle();
	vector<Card*> getTopCards(int n);
};

template <class T> GameValue<T>& GameValue<T>::operator=(const T& rhs)
{
	game->doPrimitive(new ValueChangeEvent<T>(this,rhs));
	return *this;
}
#endif
