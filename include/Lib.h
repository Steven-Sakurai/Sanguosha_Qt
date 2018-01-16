/*
 * Lib.h
 * 
 * This file contains basic elements.
 */
#ifndef _LIB_H
#define _LIB_H

//#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>

class Game;
extern Game *game;

using namespace std;

template <class T> class GameValue;

class Zone;

#define MAXPLAYER 10

enum Timing
{
	nullTiming=0,
	//Starting the game
	revealGeneral,
	initHandCard,
	gameStart,
	//Timings of a turn
	beforeTurn,
	beginTurn,
	betweenPhases,
	endTurn,
	afterTurn,
	//Timings of a phase
	beginPhase,
	endPhase,
	doDrawPhase,
	doMainPhase,
	//Timings of moving cards
	beforeMove,
	whenMove,
    afterMove,
    //Timings of using cards
    specialUse,
    whenTarget,
    whenTargeted,
    afterTarget,
    afterTargeted,
    useCleanup,
    //Timings of resolving cards
    beforeResolve,
    cardCountered,
    //Timing of yielding cards
    specialYield,
    //Special timings for using and yielding cards
    needUse,
    needYield,
    //Timings of HP reduction
    //afterHpReductionBeforeDying, //Not supporting old 周泰 now
    afterHpReduction,
    //Timings of recovering
    afterRecover,
    //Timings of damage
    beforeDamage,
    beginDamage,
    whenDamage,
    whenDamaged,
    afterDamage,
    afterDamaged,
    endDamage,
    afterEndDamage,
    //Timings of dying
    beginDying,
    duringDying,
    endDying,
    //Timings of death
    beforeRevealRole,
    onDeath,
    afterDeath,
    //Timings of judging
    doJudge,
    beforeJudgeResult,
    afterJudgeResult,
    //
	nTimings
};

enum StaticValue
{
    visibilityValue,
    distanceValue,
    maxTargetValue,
    useEffectiveness,
    slashLimitApplied,
    //
    nStaticValues
};

enum Nature
{
    Normal,
    Thunder,
    Fire
};

enum Role
{
    Lord,
    Loyalist,
    Rebel,
    Renegade
};

enum Phase
{
	standbyPhase,
	judgePhase,
	drawPhase,
	mainPhase,
	discardPhase,
	cleanupPhase
};

enum GameResult
{
    noResult,
    lordWin,
    rebelWin,
    renegadeWin
};

class GameOverException
{
public:
    GameResult result;
    GameOverException(GameResult r=noResult);
	virtual ~GameOverException();
};

class DisturbedException
{
public:
    int index;
    DisturbedException(int i=-1);
    virtual ~DisturbedException();
};

#include "Game.h"
#endif
