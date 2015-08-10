#include "Root.h"
Root::Root()
{
}
bool Root::addParent()
{
	return false;
}
bool Root::addSibling()
{
	return false;
}
void Root::addParent(Component* ParentNode)
{
	this->ParentNode = ParentNode;
}
Component* Root::clon()
{
	return NULL;
}

string Root::draw()
{
	return this->getType();
}
void Root::accept(NodeVisitor* Visitor)
{
	Visitor->visitor(this);
}


