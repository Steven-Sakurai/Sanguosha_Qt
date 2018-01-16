/*
 * ValueChangeEvent.h
 * 
 * Since it is a template class, "ValueChangeEvent.cpp" does not exist.
 */
#ifndef _VALUECHANGEEVENT_H
#define _VALUECHANGEEVENT_H

#include "Lib.h"

template <class T> class ValueChangeEvent : public PrimitiveEvent
{
	GameValue<T> *v;
	T newValue, oldValue;
public:
	ValueChangeEvent(GameValue<T> *vv,T nv) {v=vv;newValue=nv;}
	void happen() {oldValue=v->value;v->value=newValue;}
	void undo() {v->value=oldValue;}
};

#endif
