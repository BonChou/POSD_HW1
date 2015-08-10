#pragma once
#include "Composite.h"

class Node :
	public Composite
{
public:
	Node();
	bool addParent();
	void addParent(Component*);
	bool addSibling();
	Component* clon();
	string draw();
	void accept(NodeVisitor*);
};

