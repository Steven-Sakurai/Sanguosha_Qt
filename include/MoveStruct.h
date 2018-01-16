/*
 * MoveStruct.h
 * 
 */
#ifndef _MOVESTRUCT_H
#define _MOVESTRUCT_H

#include "Lib.h"

class MoveStruct
{
public:
	Card *card;
	Zone *dest;
	bool inFront;
	MoveStruct(Card *c,Zone *d,bool f=false);
};

#endif
