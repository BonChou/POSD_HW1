#include "Decorator.h"


Decorator::Decorator()
{
}


Decorator::~Decorator()
{
}

vector<Component*> Decorator::getNodeList()
{
	vector<Component*> Buffer;
	return Buffer;
}
void Decorator::addChild(Component*){}
void Decorator::addChild(Component*, Component*){}
bool Decorator::addChild(){ return false; }
void Decorator::deleteNodeList(int){}
void Decorator::deleteNodeList(){}
bool Decorator::addParent(){ return false; }
bool Decorator::addSibling(){ return false; }
void Decorator::addParent(Component*){}
void Decorator::ChangeNodeList(int, int){}
void Decorator::accept(NodeVisitor*){}

Component* Decorator::clon()
{
	Component* Buffer = NULL;
	return Buffer;
}

