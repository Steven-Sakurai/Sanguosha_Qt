/*
 * PrimitiveMoveEvent.h
 * 
 */
#ifndef _PRIMITIVEMOVEEVENT_H
#define _PRIMITIVEMOVEEVENT_H

#include "Lib.h"
#include "MoveStruct.h"
#include "MoveEvent.h"
#include "SkillEffect.h"

class PrimitiveMoveEvent: public PrimitiveEvent
{
public:
    vector<MoveStruct*> data;
    vector<Card*> oldPos;
    MoveEvent* move;
    vector<vector<SkillEffect*> > oldSkills,newSkills;
    PrimitiveMoveEvent(const vector<MoveStruct*> &d,MoveEvent *m=NULL);
	~PrimitiveMoveEvent();
	void happen();
	void undo();
    string toString(Player *p);
};

#endif
