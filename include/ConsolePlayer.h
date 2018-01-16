/*
 * ConsolePlayer.h
 * 
 */
#ifndef _CONSOLEPLAYER_H
#define _CONSOLEPLAYER_H

#include "Lib.h"

class ConsolePlayer : public ClientPlayer
{
    string parseZone(string s);
public:
    string name;
    static string roleString[4];
    static string natureString[3];
    ConsolePlayer(string n);
    virtual void inform(string message);
	int getChoice(string reason, const vector<string> &choices);
    vector<int> getMultiChoice(string reason, const vector<string> &choices, int max, const vector<bool> &mandatory);
};

#endif
