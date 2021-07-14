#pragma once

class Observer
{
public:
	Observer();
	virtual ~Observer() = 0 {}
	virtual void Update() = 0;
	virtual void UpdateSpecialPlayr() = 0;

private:

};
