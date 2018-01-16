/*
 * GamePointer.h
 * 
 * Since it is a template class, "GamePointer.cpp" does not exist.
 */
#ifndef _GAMEPOINTER_H
#define _GAMEPOINTER_H

#include "Lib.h"

template <class T> class GamePointer
{
public:
	GameValue<T*> value;
	GamePointer& operator=(T* rhs)
	{
		value=rhs;
		return *this;
	}
	T* operator->()
	{
		return value;
	}
	operator T*() const {return value;}
};

#endif
