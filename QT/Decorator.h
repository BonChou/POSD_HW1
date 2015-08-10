#pragma once
#include "Component.h"

class Decorator :
	public Component
{
public:
	Decorator();
	~Decorator();
	virtual string draw() = 0;
	vector<Component*> getNodeList();
	void addChild(Component*);
	void addChild(Component*, Component*);
	bool addChild();
	void deleteNodeList(int);
	void deleteNodeList();
	bool addParent();
	bool addSibling();
	void addParent(Component*);
	void ChangeNodeList(int, int);
	void accept(NodeVisitor*);

	Component* clon();

};

