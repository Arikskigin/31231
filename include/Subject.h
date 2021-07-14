#pragma once
#include "Observer.h"

class Subject
{
public:
	Subject();
	virtual ~Subject() = 0 {}
	virtual void RegisterObserver(Observer* pObserver) = 0;
	virtual void RemoveObserver(Observer* pObserver) = 0;
	virtual void NotifyObserversWanted() = 0;

private:

};
