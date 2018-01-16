/*
 * ClientPlayer.h
 * 
 */
#ifndef _CLIENTPLAYER_H
#define _CLIENTPLAYER_H

#include "Lib.h"

class ClientPlayer
{
public:
    virtual void inform(string message)=0;
    virtual int getChoice(string reason, const vector<string> &choices)=0;
    virtual vector<int> getMultiChoice(string reason, const vector<string> &choices, int max, const vector<bool> &mandatory)=0;
	virtual ~ClientPlayer();
};

#endif
