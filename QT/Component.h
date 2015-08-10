#pragma once
#include<string>
#include<vector>
using namespace std;
#include "NodeVisitor.h"
#include "gtest/gtest.h"
class Component
{

public:
	Component();
	void setDescription(string);
	string getDescription();
	string getType();
	void setType(string);
	int getID();
	void setID(int);
	void clearGraphic();
	virtual vector<Component*> getNodeList() = 0;
	virtual void addChild(Component*) = 0;
	virtual bool addChild() = 0;
	virtual void addChild(Component*, Component*) = 0;
	virtual bool addParent() = 0;
	virtual void addParent(Component*) = 0;
	virtual bool addSibling() = 0;
	virtual void deleteNodeList(int) = 0;
	virtual void deleteNodeList() = 0;
	virtual string draw() = 0;
	virtual Component* clon() = 0;
	virtual void ChangeNodeList(int, int) = 0;
	virtual void accept(NodeVisitor*) = 0;

	Component* ParentNode;//�������`�I �bNODE����
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	bool Select = false;
	bool PasteState = false;
	bool Copystate = false;
	bool IsExpand = true;
	bool isCollapsed = false; //��NODE�w�g��l�Q�i�}
	bool isCollapsedOne = false; //��NODE�w�g��l�Q�i�}
	vector<Component*> GraphicList;
	int Lengh = 90;
	int Width = 60;
	int GraphicCount = 0;
private:
	string Description;
	string Type;
	int ID;
	int X;
	int Y;
};
