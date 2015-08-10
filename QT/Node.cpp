#include "Node.h"
Node::Node()
{
}
bool Node::addParent()
{
	return true;
}
bool Node::addSibling()
{
	return true;
}
void Node::addParent(Component* ParentNode)
{
	this->ParentNode = ParentNode;
}
Component* Node::clon()
{
	Component* ClonNode = new Node();
	ClonNode->setDescription(this->getDescription());
	//ClonNode->setID();
	ClonNode->setType(this->getType());

	for (unsigned int Index = 0; Index < this->getNodeList().size(); Index++)
	{
		Component* ClonChild = this->getNodeList()[Index]->clon();
		ClonNode->addChild(ClonChild);
		ClonChild->addParent(ClonNode);
	}
	return ClonNode;
}
string Node::draw()
{
	return this->getType();
}
void Node::accept(NodeVisitor* Visitor)
{
	Visitor->visitor(this);
}

