#include "Composite.h"
Composite::Composite()
{
}
Composite::~Composite()
{
	for (unsigned int IndexDelete = 0; IndexDelete < NodeList.size(); IndexDelete++)
		delete NodeList[IndexDelete];
}
void Composite::addChild(Component* Buffer)
{
	bool CheckNode = false;
	for (unsigned int IndexChild = 0; IndexChild < NodeList.size(); IndexChild++)
	{
		if ((NodeList[IndexChild]->getID() == Buffer->getID()) && Buffer->getID() >= 0)//已經有相同child >=避免CLON出問題
		{ 
			NodeList[IndexChild] = Buffer->ParentNode;
			CheckNode = true;
		}
	}
	if (CheckNode == false)
		NodeList.push_back(Buffer);
}

void Composite::addChild(Component* InsertNode, Component* NewNode)
{
	for (unsigned int IndexChild = 0; IndexChild < NodeList.size(); IndexChild++)
		if (NodeList[IndexChild]->getID() == InsertNode->getID())
			NodeList.insert(NodeList.begin() + IndexChild + 1, NewNode);
}

bool Composite::addChild()	
{
	return true;
}
vector<Component*> Composite::getNodeList()
{
	return NodeList;
}
void Composite::deleteNodeList(int DeleteNodeIndex)
{
	NodeList.erase(NodeList.begin() + DeleteNodeIndex);
}
void Composite::deleteNodeList()
{
	NodeList.clear();
}

void Composite::ChangeNodeList(int NodeListIndex1, int NodeListIndex2)
{
	NodeList.insert(NodeList.begin() + NodeListIndex2 + 1, NodeList[NodeListIndex1]);
	NodeList.erase(NodeList.begin() + NodeListIndex1);
}