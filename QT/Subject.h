#pragma once
#include "Observer.h"
class Subject
{
public:
	Subject();
	~Subject();
	void attatch(Observer* observer);
	void detatch();
	void notify();
	Observer* observer;
};

