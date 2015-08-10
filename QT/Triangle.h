#pragma once
#include "Decorator.h"
class Triangle :
	public Decorator
{
public:
	Triangle();
	~Triangle();
	string draw();
};

