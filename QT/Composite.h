#pragma once
#include "Component.h"
#include <iostream>
#include <vector>
using namespace std;
class Composite :
	public Component
{
	friend class CompositeTest;
	FRIEND_TEST(CompositeTest, addChild);
public:
	Composite();
	~Composite();
	vector<Component*> getNodeList();
	void addChild(Component*);
	void addChild(Component*, Component*);
	bool addChild();
	void deleteNodeList(int);
	void deleteNodeList();
	void ChangeNodeList(int,int);
	virtual bool addParent() = 0;
	virtual bool addSibling() = 0;
	virtual void addParent(Component*) = 0;
	virtual string draw() = 0;
	virtual void accept(NodeVisitor*) = 0;
	virtual Component* clon() = 0;
	vector<Component*> NodeList;
private:
};

