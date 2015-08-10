#pragma once
#include "Composite.h"
#include "gtest/gtest.h"
class Root :
	public Composite
{
public:
	Root();
	bool addParent();
	bool addSibling();
	void addParent(Component*);
	Component* clon();
	string draw();
	void accept(NodeVisitor*);
};

