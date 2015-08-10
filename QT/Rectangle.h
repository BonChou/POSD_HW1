#pragma once
#include "Decorator.h"
class Rectangle :
	public Decorator
{
public:
	Rectangle();
	~Rectangle();
	string draw();
};

