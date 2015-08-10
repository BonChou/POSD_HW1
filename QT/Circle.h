#pragma once
#include "Decorator.h"

class Circle :
	public Decorator
{
public:
	Circle();
	string draw();
};

