#include "ComponentFactory.h"


ComponentFactory::ComponentFactory()
{
}
Component* ComponentFactory::createNode(string Description, int NewNodeID)
{
	Component* Buffer = new Node();
	Buffer->setDescription(Description);
	Buffer->setID(NewNodeID);
	Buffer->setType(NODE);
	return Buffer;
}
Component* ComponentFactory::createRoot(string Description,int NewNodeID)
{
	Component* Buffer = new Root();
	Buffer->setDescription(Description);
	Buffer->setID(NewNodeID);
	Buffer->addParent(NULL);
	Buffer->setType(ROOT);
	return Buffer;
}
Component * ComponentFactory::createRectangle()
{
	Component* Buffer = new Rectangle();
	Buffer->setType(RECTANGLE);
	return Buffer;
}
Component * ComponentFactory::createCircle()
{
	Component* Buffer = new Circle();
	Buffer->setType(CIRCLE);
	return Buffer;
}
Component * ComponentFactory::createTrinagle()
{
	Component* Buffer = new Triangle();
	Buffer->setType(TRINAGLE);
	return Buffer;
}
